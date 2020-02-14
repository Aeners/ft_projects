/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:54:56 by arlecomt          #+#    #+#             */
/*   Updated: 2017/05/02 16:37:39 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_exit(char *path, char **cmd, t_data *pvar, t_env *env)
{
	ft_freelist(env);
	ft_freetab(cmd);
	free(path);
	ft_freetab(pvar->path);
	free(pvar->oldpath);
	free(pvar->home);
	ft_printf("exit\n");
	exit(EXIT_SUCCESS);
}
