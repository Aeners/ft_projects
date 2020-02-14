/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:24:21 by arlecomt          #+#    #+#             */
/*   Updated: 2017/02/22 22:39:21 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void			translation(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
		mlx->x_tslat -= 10;
	else if (keycode == 124)
		mlx->x_tslat += 10;
	else if (keycode == 125)
		mlx->y_tslat += 10;
	else
		mlx->y_tslat -= 10;
}

static void			zoom(int keycode, t_mlx *mlx)
{
	if (keycode == 69)
	{
		mlx->x_scale += 1;
		mlx->y_scale += 1;
	}
	else if (keycode == 78)
	{
		mlx->x_scale -= 1;
		mlx->y_scale -= 1;
	}
}

static int			keys(int keycode, void *param)
{
	ft_trace(param, &cleaner);
	if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->img);
		mlx_destroy_window(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->win);
		free(param);
		exit(1);
	}
	else if (keycode == 13 || keycode == 1)
		((t_mlx *)param)->z_scale += (keycode == 13 ? 1 : -1);
	else if (keycode >= 123 && keycode <= 126)
		translation(keycode, param);
	else if (keycode == 69 || keycode == 78)
		zoom(keycode, param);
	else if (keycode == 49)
	{
		((t_mlx *)param)->def = (((t_mlx *)param)->def + rand()) % 0xffffff;
		((t_mlx *)param)->col_z = (((t_mlx *)param)->col_z + rand()) % 0xffffff;
	}
	else if (keycode == 18 || keycode == 19)
		((t_mlx *)param)->proj = (keycode == 18 ? &parallel : &isometric);
	else if (keycode == 29)
		((t_mlx *)param)->proj = &defcon5;
	ft_trace(param, &printer);
	return (0);
}

static int			mouse(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	ft_trace(param, &cleaner);
	if (button == 4)
		zoom(69, param);
	else if (button == 5)
		zoom(78, param);
	ft_trace(param, &printer);
	return (0);
}

void				ft_fdf(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH_WIN, HEIGHT_WIN, "new");
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH_IMG, HEIGHT_IMG);
	mlx->data = mlx_get_data_addr(mlx->img, &(mlx)->bpp, &(mlx)->sl, &(mlx)->e);
	mlx_hook(mlx->win, 2, 3, keys, mlx);
	mlx_mouse_hook(mlx->win, mouse, mlx);
	ft_trace(mlx, &printer);
	mlx_loop(mlx->mlx_ptr);
}
