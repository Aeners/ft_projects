/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:43:03 by arlecomt          #+#    #+#             */
/*   Updated: 2017/02/22 19:51:03 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_color(t_data **pos, char **str, int *i, int *j)
{
	if (**str == '0')
		(*str)++;
	if (**str == 'x')
		(*str)++;
	pos[*i][*j].color = ft_atoi_base(*str, 16);
	*str += 6;
}

static void		ft_col(t_data **pos, char **str, int *i, int *j)
{
	while (**str == ' ' || **str == '\t' || **str == '\n')
		(*str)++;
	if (ft_isdigit(**str) || **str == '-')
		pos[*i][*j].z = ft_atoi(*str);
	pos[*i][*j].x = *j;
	pos[*i][*j].y = *i;
	while (ft_isdigit(**str) || **str == '-')
		(*str)++;
	if (**str == ',')
	{
		(*str)++;
		ft_color(pos, str, i, j);
	}
	else
		pos[*i][*j].color = 0;
	(*j)++;
}

t_data			**ft_parsing(char *str, t_mlx *mlx)
{
	t_data		**pos;
	int			i;
	int			j;

	i = 0;
	j = 0;
	pos = NULL;
	ft_checkvalid(str, &mlx->col, &mlx->lines);
	if (!(pos = (t_data**)malloc(sizeof(t_data*) * mlx->lines + 1)))
		ft_printerror(-42);
	while (i < mlx->lines)
	{
		if (!(pos[i] = (t_data*)malloc(sizeof(t_data) * mlx->col + 1)))
			ft_printerror(-42);
		while (j < mlx->col)
			ft_col(pos, &str, &i, &j);
		j = 0;
		i++;
	}
	return (pos);
}
