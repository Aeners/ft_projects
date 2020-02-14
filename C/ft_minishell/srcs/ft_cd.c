/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:16:56 by AL                #+#    #+#             */
/*   Updated: 2017/05/13 17:11:24 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		cd_errors(char **cmd)
{
	struct stat			stats;

	if (access(cmd[1], F_OK) != 0)
		ft_error(0, cmd[0], cmd[1]);
	else
	{
		if (stat(cmd[1], &stats) == 0)
		{
			if (!(S_IFDIR >> 9 == (stats.st_mode >> 9)))
				ft_error(1, cmd[0], cmd[1]);
			else if (!(stats.st_mode & S_IXUSR))
				ft_error(2, cmd[0], cmd[1]);
		}
		else
			ft_error(-42, NULL, NULL);
	}
}

static void		minus_cd(t_data *pvar, t_env *env, char *curr_path)
{
	char				*tmp;

	if (pvar->oldpath)
	{
		tmp = ft_strjoin("OLDPWD=", curr_path);
		check_env(&env, tmp);
		free(tmp);
		ft_printf("%s\n", pvar->oldpath);
		chdir(pvar->oldpath);
	}
	else
		write(2, "OLDPWD not set\n", 15);
}

void			ft_cd(char **cmd, t_data *pvar, t_env *env)
{
	char				curr_path[1024];
	char				*tmp;

	getcwd(curr_path, sizeof(curr_path));
	if (!cmd[1])
	{
		if (pvar->home == NULL)
			return ;
		tmp = ft_strjoin("OLDPWD=", curr_path);
		check_env(&env, tmp);
		free(tmp);
		chdir(pvar->home);
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
		minus_cd(pvar, env, curr_path);
	else if (chdir(cmd[1]) != 0)
		cd_errors(cmd);
	else if (pvar->home != NULL)
	{
		tmp = ft_strjoin("OLDPWD=", curr_path);
		check_env(&env, tmp);
		free(tmp);
	}
}
