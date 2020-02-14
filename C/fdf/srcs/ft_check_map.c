/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:00:46 by arlecomt          #+#    #+#             */
/*   Updated: 2017/02/22 19:54:46 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_printerror(int i)
{
	if (i == 0)
		ft_putstr_fd("Fail openning", 2);
	if (i == -1)
		ft_putstr_fd("No map", 2);
	if (i == -2)
		ft_putstr_fd("Map invalide", 2);
	if (i == -3)
		ft_putstr_fd("Code couleur invalide", 2);
	if (i == -4)
		ft_putstr_fd("Out of window !", 2);
	if (i == -42)
		ft_putstr_fd("Erreur Malloc", 2);
	exit(1);
}

static void		ft_checkcolor(char *str, int *i)
{
	int		count;

	count = 0;
	if (str[*i] == '0')
		(*i)++;
	if (str[*i] == 'x')
		(*i)++;
	while (ft_isdigit(str[*i]) || (str[*i] > 64 && str[*i] < 71))
	{
		(*i)++;
		count++;
	}
	if (count != 6)
		ft_printerror(-3);
}

static void		ft_checkcol(int *save, int *nl, int *nc)
{
	if (!*save)
		*save = *nc;
	else
	{
		if (*save != *nc)
			ft_printerror(-2);
	}
	*nc = 0;
	(*nl)++;
}

void			ft_checkvalid(char *s, int *nc, int *nl)
{
	int		i;
	int		save;

	i = 0;
	save = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (ft_isdigit(s[i]) || (s[i] == '-' && ft_isdigit(s[i + 1])))
			(*nc)++;
		while (ft_isdigit(s[i]) || (s[i] == '-' && ft_isdigit(s[i + 1])))
			i++;
		if (s[i] == ',')
		{
			i++;
			ft_checkcolor(s, &i);
		}
		if (!ft_isdigit(s[i]) && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
			ft_printerror(-2);
		if (s[i++] == '\n')
			ft_checkcol(&save, nl, nc);
	}
	*nc = save;
}
