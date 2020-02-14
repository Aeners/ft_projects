/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrison <abrison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 16:55:14 by abrison           #+#    #+#             */
/*   Updated: 2016/06/08 16:02:00 by abrison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# define BUFFER (27*21)

typedef int			t_bool;
enum {false, true};

typedef struct		s_tetrim
{
	int				x;
	int				y;
	char			id;
	char			**shape;
	char			*coord;
	t_bool			used;
	struct s_tetrim	*next;
}					t_tetrim;

typedef struct		s_group
{
	int				size;
	int				maplen;
	char			**map;
	char			**save;
	struct s_tetrim	*premier;
	struct s_tetrim	*curr;
}					t_group;

t_group				*init();
void				ft_iserror();
t_tetrim			*fill_shape_diez(t_tetrim *curr, int *x, int y);
void				special_test(char *pack, int p);
int					count_shape_id(t_tetrim *curr);
void				pre_launcher(int argc, char **argv);
void				launcher(t_group *grp, char *pack);
void				insert(t_group *grp, char id);
void				show_tetrim(t_group *grp);
void				show_tab(char **tab);
void				ft_tracking(t_group *grp, t_tetrim *curr);
void				ft_save_check(t_group *grp);
void				ft_get_map(t_group *grp);
void				check_next(char *pack, int p);
void				coord_xy(t_group *grp, char **shape, int y);
int					getdiez(char *pack);
int					ft_allused(t_group *grp);
int					count_dot_x(char *line);
int					check(t_tetrim *curr);

#endif
