/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:00:28 by arlecomt          #+#    #+#             */
/*   Updated: 2017/02/22 22:40:01 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	i;

	if (x <= WIDTH_IMG && y <= HEIGHT_IMG && x >= 0 && y >= 0)
	{
		i = mlx->sl * y + x * 4;
		mlx->data[i] = color & 0xff;
		mlx->data[++i] = color >> 8 & 0xff;
		mlx->data[++i] = color >> 16;
	}
}

static char		*get_map(int fd)
{
	char		*line;
	char		*readder;
	char		*tmp;

	line = ft_strnew(0);
	while (get_next_line(fd, &readder) > 0)
	{
		tmp = readder;
		line = ft_strjoin(line, readder);
		ft_memdel((void **)&tmp);
		tmp = line;
		line = ft_strjoin(line, "\n");
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&readder);
	return (line);
}

int				main(int ac, char **av)
{
	int				fd;
	t_mlx			*mlx;
	char			*str;

	fd = 0;
	if (ac != 2)
		ft_printerror(-1);
	else
	{
		if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
			ft_printerror(-42);
		ft_init_integers(8, &mlx->x_scale, &mlx->y_scale, &mlx->z_scale, \
		&mlx->x_tslat, &mlx->y_tslat, &mlx->lines, &mlx->col, &mlx->boolean);
		mlx->col_z = 0xff0000;
		mlx->def = 0x00ff00;
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_printerror(0);
		str = get_map(fd);
		mlx->coord = ft_parsing(str, mlx);
		mlx->proj = &parallel;
		ft_fdf(mlx);
		ft_memdel((void**)&mlx);
	}
}
