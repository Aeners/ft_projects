/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:20:51 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/27 18:56:23 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_freelist(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		ft_strdel(&(tmp->var));
		free(tmp);
	}
}

void			ft_freetab(char **tab)
{
	int			i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_strdel((&tab[i]));
		i++;
	}
	ft_memdel((void **)&tab);
}
