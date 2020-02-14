/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:00:29 by arlecomt          #+#    #+#             */
/*   Updated: 2017/02/22 20:35:41 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		bresenham(t_sgmt c_, t_mlx *mlx, int color)
{
	int			s_x;
	int			s_y;
	int			err;
	int			e2;

	s_x = (c_.x_1 < c_.x_2 ? 1 : -1);
	s_y = (c_.y_1 < c_.y_2 ? 1 : -1);
	err = (c_.d_x > c_.d_y ? c_.d_x : -c_.d_y) / 2;
	while (1)
	{
		put_pixel(mlx, c_.x_1, c_.y_1, color);
		if (c_.x_1 == c_.x_2 && c_.y_1 == c_.y_2)
			break ;
		e2 = err;
		if (e2 > -c_.d_x)
		{
			err -= c_.d_y;
			c_.x_1 += s_x;
		}
		if (e2 < c_.d_y)
		{
			err += c_.d_x;
			c_.y_1 += s_y;
		}
	}
}

void			cleaner(int i, int j, t_mlx *mlx)
{
	t_sgmt		c_;

	if (j + 1 < mlx->col)
	{
		c_ = mlx->proj(i, j, 0, mlx);
		c_.d_x = abs(c_.x_2 - c_.x_1);
		c_.d_y = abs(c_.y_2 - c_.y_1);
		bresenham(c_, mlx, 0);
	}
	if (i + 1 < mlx->lines)
	{
		c_ = mlx->proj(i, j, 1, mlx);
		c_.d_x = abs(c_.x_2 - c_.x_1);
		c_.d_y = abs(c_.y_2 - c_.y_1);
		bresenham(c_, mlx, 0);
	}
}

static int		get_color(int i, int j, t_mlx *mlx, int *b)
{
	*b = 1;
	if (j + 1 < mlx->col && i + 1 < mlx->lines)
	{
		if (mlx->coord[i][j].z * ZS || mlx->coord[i][j + 1].z * ZS \
		|| mlx->coord[i + 1][j].z * ZS)
			return (mlx->col_z);
	}
	return (mlx->def);
}

void			printer(int i, int j, t_mlx *mlx)
{
	t_sgmt		c_;

	if (mlx->coord[i][j].color == 0 || mlx->boolean == 1)
		mlx->coord[i][j].color = get_color(i, j, mlx, &mlx->boolean);
	if (j + 1 < mlx->col)
	{
		c_ = mlx->proj(i, j, 0, mlx);
		c_.d_x = abs(c_.x_2 - c_.x_1);
		c_.d_y = abs(c_.y_2 - c_.y_1);
		bresenham(c_, mlx, mlx->coord[i][j].color);
	}
	if (i + 1 < mlx->lines)
	{
		c_ = mlx->proj(i, j, 1, mlx);
		c_.d_x = abs(c_.x_2 - c_.x_1);
		c_.d_y = abs(c_.y_2 - c_.y_1);
		bresenham(c_, mlx, mlx->coord[i][j].color);
	}
}

void			ft_trace(t_mlx *mlx, void (*fct)(int, int, t_mlx *))
{
	int			i;
	int			j;

	i = 0;
	while (i < (int)mlx->lines)
	{
		j = 0;
		while (j < (int)mlx->col)
		{
			fct(i, j, mlx);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img, 0, 0);
}
