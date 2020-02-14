/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:34:35 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 18:32:20 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define FT_PRINTF_CONV "sSpdiouxXDOUcC"
# define FT_PRINTF_FLAGS "#0-+ hhhllljz"
# define FT_PRINTF_LENGTH "hhhllljz"
# define FT_PRINTF_INT "dDioOuUxX"
# define FT_PRINTF_L "DOUCS"

# define MAX_UNI 0x10FFFF

# define BUFF_SIZE 1000

typedef struct		s_type
{
	char			flags[15];
	long long		precision;
	long long		padding;
	char			conv;
	int				base;
}					t_type;

typedef struct		s_buff
{
	char			content[BUFF_SIZE];
	int				index;
	int				ret;
}					t_buff;

int					ft_printf(const char *restrict format, ...);

int					ft_putbuffer(t_buff *buff, void *adding, size_t size);
int					ft_print_buff(t_buff *buff);
void				ft_printf_itoa(long long n, int base, char *value);

void				ft_padding(t_buff *buff, t_type *info, long long len);
void				ft_precision_int(t_buff *buff, t_type *info, \
					long long len);

void				ft_int(t_buff *buff, t_type *info, long long n);

void				ft_char(t_buff *buff, t_type *info, wchar_t c);
void				ft_charadd(t_type *info, wchar_t c, char *char_oct, int *i);
void				ft_string(t_buff *buff, t_type *info, wchar_t *s);

void				ft_ptrhexa(t_buff *buff, t_type *info, \
					unsigned long p);

void				ft_percent(t_buff *buff, t_type *info);

int					ft_size_bin(int c);

#endif
