/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:00:56 by arlecomt          #+#    #+#             */
/*   Updated: 2017/02/22 22:39:54 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>

# define WIDTH_WIN 2000
# define HEIGHT_WIN 1200
# define WIDTH_IMG 2000
# define HEIGHT_IMG 1200

# define XS mlx->x_scale
# define YS mlx->y_scale
# define ZS mlx->z_scale
# define XT mlx->x_tslat
# define YT mlx->y_tslat

typedef	struct		s_data
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_data;

typedef struct		s_sgmt
{
	int				x_1;
	int				x_2;
	int				y_1;
	int				y_2;
	int				d_x;
	int				d_y;
}					t_sgmt;

typedef struct		s_mlx
{
	t_sgmt			(*proj)(int i, int j, int dir, struct s_mlx *mlx);
	int				lines;
	int				col;
	t_data			**coord;
	void			*mlx_ptr;
	void			*win;
	void			*img;
	char			*data;
	int				sl;
	int				bpp;
	int				e;
	int				x_scale;
	int				y_scale;
	int				z_scale;
	int				x_tslat;
	int				y_tslat;
	int				boolean;
	int				col_z;
	int				def;
}					t_mlx;

void				ft_errors();
void				ft_printerror(int i);
void				ft_checkvalid(char *str, int *nc, int *nl);

t_data				**ft_parsing(char *map, t_mlx *mlx);

void				ft_fdf(t_mlx *mlx);

void				ft_trace(t_mlx *mlx, void (*fct)(int, int, t_mlx *));
void				cleaner(int i, int j, t_mlx *mlx);
void				printer(int i, int j, t_mlx *mlx);

t_sgmt				parallel(int i, int j, int dir, struct s_mlx *mlx);
t_sgmt				isometric(int i, int j, int dir, struct s_mlx *mlx);
t_sgmt				defcon5(int i, int j, int dir, struct s_mlx *mlx);

void				put_pixel(t_mlx *mlx, int x, int y, int color);

#endif
