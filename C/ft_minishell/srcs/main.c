/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:35:53 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/27 16:03:36 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_error(int err, char *cmd, char *arg)
{
	if (err == -1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
	}
	else if (err == 0)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": no such file or directory: ", 2);
		ft_putendl_fd(arg, 2);
	}
	else if (err == 1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": not a directory: ", 2);
		ft_putendl_fd(arg, 2);
	}
	else if (err == 2)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": permission denied: ", 2);
		ft_putendl_fd(arg, 2);
	}
	else if (err == -42)
		ft_putendl_fd("Unknown error", 2);
}

void			ft_init_all_paths(char **pathtab)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while (pathtab[i])
	{
		tmp = pathtab[i];
		pathtab[i] = ft_strjoin(pathtab[i], "/");
		free(tmp);
		i++;
	}
}

static void		norme_it(t_env *tmp, t_data *pvar)
{
	char				*tmp2;

	tmp2 = NULL;
	if (ft_strncmp("HOME=", tmp->var, 5) == 0)
	{
		if (pvar->home != NULL)
			free(pvar->home);
		pvar->home = ft_strdup(tmp->var + 5);
	}
	else if (ft_strncmp("PATH=", tmp->var, 5) == 0)
	{
		if (pvar->path != NULL)
			ft_freetab(pvar->path);
		tmp2 = ft_strdup(tmp->var + 5);
		pvar->path = ft_strsplit(tmp2, ':');
		free(tmp2);
		ft_init_all_paths(pvar->path);
	}
	else if (ft_strncmp("OLDPWD=", tmp->var, 7) == 0)
	{
		if (pvar->oldpath != NULL)
			free(pvar->oldpath);
		pvar->oldpath = ft_strdup(tmp->var + 7);
	}
}

void			get_info(t_data *pvar, t_env *env)
{
	t_env				*tmp;

	tmp = env;
	if (!tmp)
	{
		ft_strdel(&pvar->home);
		ft_strdel(&pvar->oldpath);
		ft_freetab(pvar->path);
		pvar->path = NULL;
	}
	while (tmp)
	{
		norme_it(tmp, pvar);
		tmp = tmp->next;
	}
}

int				main(int ac, char **av, char **envp)
{
	t_env		*env;
	t_data		pvar;
	int			i;

	(void)ac;
	(void)av;
	env = NULL;
	i = 0;
	ft_memset(&pvar, 0, sizeof(pvar));
	while (envp[i])
		push_env(&env, envp[i++]);
	pvar.nb_env = i;
	ft_minishell(env, pvar);
	return (0);
}
