/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:36:30 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/27 18:14:59 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			print_env(t_env *env)
{
	while (env)
	{
		ft_putendl(env->var);
		env = env->next;
	}
}

static char		**copypasta(char **src, int i)
{
	int			len;
	int			j;
	char		**ret;

	len = 0;
	j = 0;
	while (src[len])
		len++;
	if (!(ret = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	while (src[i])
	{
		ret[j] = ft_strdup(src[i]);
		i++;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

static t_env	*copylst(t_env *env)
{
	t_env			*tmp;
	t_env			*head;
	t_env			*new;

	tmp = env;
	new = ft_memalloc(sizeof(t_env));
	head = new;
	new->var = ft_strdup(tmp->var);
	while (tmp->next)
	{
		new->next = ft_memalloc(sizeof(t_env));
		new->next->var = ft_strdup(tmp->next->var);
		new->next->next = NULL;
		new = new->next;
		tmp = tmp->next;
	}
	return (head);
}

static void		clear_env(t_env **env, int *i)
{
	(*i)++;
	ft_freelist(*env);
	*env = NULL;
}

void			ft_env(char **cmd, t_env *env, t_data *pvar)
{
	char		**new_cmd;
	int			i;
	t_env		*env_tmp;

	i = 1;
	env_tmp = (env ? copylst(env) : NULL);
	if (!cmd[i])
		print_env(env_tmp);
	else
	{
		if (ft_strcmp(cmd[i], "-i") == 0)
			clear_env(&env_tmp, &i);
		if (cmd[i] && cmd[i][0] != '=' && ft_strchr(cmd[i], '='))
			check_env(&env_tmp, cmd[i++]);
		if (cmd[i])
		{
			new_cmd = copypasta(cmd, i);
			executions(pvar, env_tmp, new_cmd);
		}
		else
			print_env(env_tmp);
	}
	ft_freelist(env_tmp);
}
