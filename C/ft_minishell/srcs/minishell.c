/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:02:56 by AL                #+#    #+#             */
/*   Updated: 2017/04/29 17:55:47 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**get_cmd(void)
{
	int			ret;
	char		buf[2];
	char		*tmp;
	char		**cmd;

	tmp = (char*)malloc(sizeof(char));
	ft_bzero(buf, 2);
	ft_bzero(tmp, 1);
	while ((ret = read(0, &buf, 1)) > 0 && !ft_strchr(buf, '\n'))
	{
		buf[ret] = '\0';
		if (buf[0] != '\t')
			tmp = ft_freejoin(tmp, buf);
	}
	if (tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	cmd = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	return (cmd);
}

static void		ft_prompt(void)
{
	char		cwd[1024];

	getcwd(cwd, sizeof(cwd));
	ft_putstr(GREEN);
	ft_putstr(cwd);
	ft_putstr(" $>");
	ft_putstr(DEFAULT);
}

char			*find_cmd(t_data pvar, char *cmd)
{
	int			i;
	char		*tmp_path;

	i = 0;
	while (pvar.path && pvar.path[i])
	{
		tmp_path = ft_strjoin(pvar.path[i], cmd);
		if (access(tmp_path, F_OK) == 0 && !ft_strstr(BUILTIN, cmd))
		{
			free(tmp_path);
			return (ft_strjoin(pvar.path[i], cmd));
		}
		free(tmp_path);
		i++;
	}
	return (NULL);
}

void			executions(t_data *pvar, t_env *env, char **cmd)
{
	char		*path;

	get_info(pvar, env);
	if ((path = find_cmd(*pvar, cmd[0])) != NULL)
		exec_present(path, cmd, env);
	else
		exec_absent(path, cmd, pvar, env);
}

void			ft_minishell(t_env *env, t_data pvar)
{
	char		**cmd;
	char		*tmp;

	while (42)
	{
		ft_prompt();
		cmd = get_cmd();
		if (cmd && ((tmp = ft_strtrim(cmd[0])) != NULL))
		{
			ft_strdel(&tmp);
			executions(&pvar, env, cmd);
		}
		else
			ft_freetab(cmd);
	}
}
