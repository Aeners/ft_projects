/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:24:56 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/27 18:37:55 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_setenv(char **cmd, t_env *env)
{
	if (!cmd[1])
		ft_putstr_fd("usage: setenv 'env_variable'='value'\n", 2);
	else if (cmd[1][0] != '=' && ft_strchr(cmd[1], '='))
		check_env(&env, cmd[1]);
	else
	{
		if (!ft_strchr(cmd[1], '='))
			ft_putstr_fd("usage: setenv 'env_variable'='value'\n", 2);
		else
		{
			ft_putstr_fd("setenv: no env variable = ", 2);
			ft_putstr_fd(cmd[1], 2);
			ft_putstr_fd("\n", 2);
		}
	}
}

void			ft_unsetenv(char **cmd, t_env *env, t_data *pvar)
{
	if (!cmd[1])
		ft_putstr_fd("usage: setenv 'env_variable'='value'\n", 2);
	else
	{
		delone_env(&env, cmd[1]);
		if (!ft_strcmp(cmd[1], "HOME"))
		{
			free(pvar->home);
			pvar->home = NULL;
		}
		if (!ft_strcmp(cmd[1], "PATH"))
		{
			ft_freetab(pvar->path);
			pvar->path = NULL;
		}
		if (!ft_strcmp(cmd[1], "OLDPWD"))
		{
			free(pvar->oldpath);
			pvar->oldpath = NULL;
		}
	}
}
