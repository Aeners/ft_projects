/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:26:22 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/22 12:26:23 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		special_test(char *pack, int p)
{
	if (pack[p] == '.' && pack[p - 1] == '#' && pack[p + 1] == '#')
		ft_iserror();
}

int			count_shape_id(t_tetrim *curr)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = -1;
	while (curr->shape[++j] != NULL)
	{
		i = -1;
		while (curr->shape[j][++i] != '\0')
		{
			if (curr->shape[j][i] == curr->id)
				count++;
		}
	}
	return (count);
}

t_tetrim	*fill_shape_diez(t_tetrim *curr, int *x, int y)
{
	curr->shape[y][*x] = curr->id;
	*x += 1;
	return (curr);
}
