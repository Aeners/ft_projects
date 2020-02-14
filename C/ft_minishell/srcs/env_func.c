/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:55:03 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/27 19:06:50 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*add_env(char *var)
{
	t_env		*tmp;

	if (!(tmp = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	tmp->next = NULL;
	if (!var)
		tmp->var = NULL;
	else
		tmp->var = ft_strdup(var);
	return (tmp);
}

void			push_env(t_env **lst, char *var)
{
	t_env		*tmp;

	tmp = *lst;
	if (!tmp)
		*lst = add_env(var);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_env(var);
	}
}

void			delone_env(t_env **lst, char *var)
{
	int			eq;
	t_env		*tmp;
	t_env		*tmp2;

	eq = 0;
	while (var[eq])
		eq++;
	tmp = *lst;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		if (ft_strncmp(tmp2->var, var, eq) == 0 && tmp2->var[eq] == '=')
		{
			if (tmp2)
			{
				tmp->next = tmp2->next;
				free(tmp2->var);
				free(tmp2);
				return ;
			}
		}
		tmp = tmp->next;
	}
	write(2, "Variable not found\n", 19);
}

void			check_env(t_env **lst, char *var)
{
	int			equal;
	t_env		*tmp;
	char		*tmp2;

	equal = 0;
	while (var[equal] != '=' && var)
		equal++;
	tmp = *lst;
	while (tmp)
	{
		if (ft_strncmp(var, tmp->var, equal) == 0)
		{
			tmp2 = tmp->var;
			tmp->var = ft_strdup(var);
			free(tmp2);
			return ;
		}
		tmp = tmp->next;
	}
	push_env(lst, var);
}

char			**fill_envp(t_env *env)
{
	char		**ret;
	t_env		*tmp;
	int			len;
	int			i;

	tmp = env;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	ret = ft_memalloc(sizeof(char **) * (len + 1));
	i = 0;
	tmp = env;
	while (i < len)
	{
		ret[i] = ft_strdup(tmp->var);
		tmp = tmp->next;
		i++;
	}
	return (ret);
}
