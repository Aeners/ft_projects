/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:42:22 by arlecomt          #+#    #+#             */
/*   Updated: 2017/02/22 22:40:30 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_sgmt			parallel(int i, int j, int dir, struct s_mlx *mlx)
{
	t_sgmt			c_;

	if (!dir)
	{
		c_.x_1 = mlx->coord[i][j].x * XS + XT + mlx->coord[i][j].z * ZS;
		c_.y_1 = mlx->coord[i][j].y * YS + YT + mlx->coord[i][j].z * ZS;
		c_.x_2 = mlx->coord[i][j + 1].x * XS + XT + mlx->coord[i][j + 1].z * ZS;
		c_.y_2 = mlx->coord[i][j + 1].y * YS + YT + mlx->coord[i][j + 1].z * ZS;
	}
	else
	{
		c_.x_1 = mlx->coord[i][j].x * XS + XT + mlx->coord[i][j].z * ZS;
		c_.y_1 = mlx->coord[i][j].y * YS + YT + mlx->coord[i][j].z * ZS;
		c_.x_2 = mlx->coord[i + 1][j].x * XS + XT + mlx->coord[i + 1][j].z * ZS;
		c_.y_2 = mlx->coord[i + 1][j].y * YS + YT + mlx->coord[i + 1][j].z * ZS;
	}
	return (c_);
}

t_sgmt			defcon5(int i, int j, int dir, struct s_mlx *mlx)
{
	t_sgmt			c_;

	if (!dir)
	{
		c_.x_1 = (mlx->coord[i][j].x * XS) - (mlx->coord[i][j].y * \
		YS) + XT;
		c_.y_1 = (mlx->coord[i][j].x * XS + mlx->coord[i][j].y * YS) \
		/ 2 - mlx->coord[i][j].z * ZS + XT;
		c_.x_2 = (mlx->coord[i][j + 1].x * XS) - (mlx->coord[i][j + 1].y \
		* YS) + XT;
		c_.y_2 = (mlx->coord[i][j + 1].x * XS + mlx->coord[i][j + 1].y * \
		YS) / 2 - mlx->coord[i][j + 1].z * ZS + XT;
	}
	else
	{
		c_.x_1 = (mlx->coord[i][j].x * XS) - (mlx->coord[i][j].y * \
		YS) + YT;
		c_.y_1 = (mlx->coord[i][j].x * XS + mlx->coord[i][j].y * YS) \
		/ 2 - mlx->coord[i][j].z * ZS + YT;
		c_.x_2 = (mlx->coord[i + 1][j].x * XS) - (mlx->coord[i + 1][j].y \
		* YS) + YT;
		c_.y_2 = (mlx->coord[i + 1][j].x * XS + mlx->coord[i + 1][j].y * \
		YS) / 2 - mlx->coord[i + 1][j].z * ZS + YT;
	}
	return (c_);
}

t_sgmt			isometric(int i, int j, int dir, struct s_mlx *mlx)
{
	t_sgmt			c_;

	if (!dir)
	{
		c_.x_1 = (mlx->coord[i][j].x * XS) - (mlx->coord[i][j].y * \
		YS) + XT;
		c_.y_1 = (mlx->coord[i][j].x * XS + mlx->coord[i][j].y * YS) \
		/ 2 - mlx->coord[i][j].z * ZS + YT;
		c_.x_2 = (mlx->coord[i][j + 1].x * XS) - (mlx->coord[i][j + 1].y \
		* YS) + XT;
		c_.y_2 = (mlx->coord[i][j + 1].x * XS + mlx->coord[i][j + 1].y * \
		YS) / 2 - mlx->coord[i][j + 1].z * ZS + YT;
	}
	else
	{
		c_.x_1 = (mlx->coord[i][j].x * XS) - (mlx->coord[i][j].y * \
		YS) + XT;
		c_.y_1 = (mlx->coord[i][j].x * XS + mlx->coord[i][j].y * YS) \
		/ 2 - mlx->coord[i][j].z * ZS + YT;
		c_.x_2 = (mlx->coord[i + 1][j].x * XS) - (mlx->coord[i + 1][j].y \
		* YS) + XT;
		c_.y_2 = (mlx->coord[i + 1][j].x * XS + mlx->coord[i + 1][j].y * \
		YS) / 2 - mlx->coord[i + 1][j].z * ZS + YT;
	}
	return (c_);
}
