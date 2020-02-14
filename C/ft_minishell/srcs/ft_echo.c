/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 00:12:27 by AL                #+#    #+#             */
/*   Updated: 2017/04/29 18:28:45 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*check_var(char *var, t_env *env)
{
	t_env		*tmp;
	int			len;

	tmp = env;
	len = ft_strlen(var);
	while (tmp)
	{
		if (var[0] != '\0' && ft_strncmp(var, tmp->var, len) == 0 &&\
		tmp->var[len] == '=')
			return (tmp->var + len + 1);
		tmp = tmp->next;
	}
	return (NULL);
}

void			ft_echo(char **cmd, t_env *env)
{
	int			i;
	char		*env_var;

	if (cmd[1])
	{
		i = (ft_strcmp(cmd[1], "-n") == 0 ? 2 : 1);
		while (cmd[i])
		{
			if (cmd[i][0] == '$' &&\
			(env_var = check_var(cmd[i] + 1, env)) != NULL)
				ft_printf(env_var);
			else
				ft_printf("%s", cmd[i]);
			if (cmd[i + 1])
				write(1, " ", 1);
			i++;
		}
		if (ft_strcmp(cmd[1], "-n") != 0)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
