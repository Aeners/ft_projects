/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:17:08 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/19 17:26:11 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			modifier_ouxx(long long n, t_type *info, char *value)
{
	if (ft_strchrn(info->flags, 'l') == 2)
		ft_printf_itoa((unsigned long long)n, info->base, value);
	else if (ft_strchr(info->flags, 'l'))
		ft_printf_itoa((unsigned long)n, info->base, value);
	else if (ft_strchrn(info->flags, 'h') == 2)
		ft_printf_itoa((unsigned char)n, info->base, value);
	else if (ft_strchr(info->flags, 'h'))
		ft_printf_itoa((unsigned short)n, info->base, value);
	else if (ft_strchr(info->flags, 'j'))
		ft_printf_itoa((uintmax_t)n, info->base, value);
	else if (ft_strchr(info->flags, 'z'))
		ft_printf_itoa((size_t)n, info->base, value);
	else
		ft_printf_itoa((unsigned int)n, info->base, value);
	if (info->conv == 'x')
		ft_strtolower(value);
}

static void			ft_modifier(long long n, t_type *info, char *value)
{
	if (info->conv != 'd' && info->conv != 'i')
		modifier_ouxx(n, info, value);
	else if (ft_strchrn(info->flags, 'l') == 2)
		ft_printf_itoa((long long)n, info->base, value);
	else if (ft_strchr(info->flags, 'l'))
		ft_printf_itoa((long)n, info->base, value);
	else if (ft_strchrn(info->flags, 'h') == 2)
		ft_printf_itoa((signed char)n, info->base, value);
	else if (ft_strchr(info->flags, 'h'))
		ft_printf_itoa((short)n, info->base, value);
	else if (ft_strchr(info->flags, 'j'))
		ft_printf_itoa((intmax_t)n, info->base, value);
	else if (ft_strchr(info->flags, 'z'))
		ft_printf_itoa((signed long)n, info->base, value);
	else
		ft_printf_itoa((int)n, info->base, value);
}

static void			ft_sign(char *sign, t_type *info, char *value, int *i)
{
	*i = 0;
	ft_bzero(sign, 5);
	if (info->conv == 'd' || info->conv == 'i')
	{
		if (value[0] == '-')
			sign[(*i)++] = '-';
		else if (ft_strchr(info->flags, '+'))
			sign[(*i)++] = '+';
		else if (ft_strchr(info->flags, ' '))
			sign[(*i)++] = ' ';
	}
	else if (ft_strchr(info->flags, '#') && !(!value[1] && value[0] == '0' \
	&& info->precision != 0) && !(info->base == 16 && !(info->precision)))
	{
		if (info->conv == 'x')
			ft_strncpy(sign, "0x", 2);
		else if (info->conv == 'X')
			ft_strncpy(sign, "0X", 2);
		else if (info->conv == 'o')
			ft_strncpy(sign, "0", 1);
		*i = (info->conv == 'o' ? 1 : 2);
	}
}

static long long	ft_padlen(t_type *info, size_t len, int i, int boolean)
{
	if (boolean)
		return (info->precision > (int)len ? info->precision + i : len + i);
	if (info->conv == 'd' || info->conv == 'i')
		info->base = 10;
	else if (info->conv == 'x' || info->conv == 'X')
		info->base = 16;
	else if (info->conv == 'o')
		info->base = 8;
	else if (info->conv == 'u')
		info->base = -10;
	return (0);
}

void				ft_int(t_buff *buff, t_type *info, long long n)
{
	char		value[100];
	char		sign[5];
	size_t		len;
	int			i;

	ft_padlen(info, 0, 0, 0);
	ft_modifier(n, info, value);
	ft_sign(sign, info, value, &i);
	if ((len = 0) || !(info->precision == 0 && n == 0))
		len = (sign[0] == '-' ? ft_strlen(value) - 1 : ft_strlen(value));
	if (!(ft_strchr(info->flags, '-')) && !(ft_strchr(info->flags, '0') && \
	info->precision < 0))
		ft_padding(buff, info, ft_padlen(info, len, i, 1));
	if (!(ft_putbuffer(buff, sign, i)))
		exit(-1);
	if (!(ft_strchr(info->flags, '-')) && ft_strchr(info->flags, '0') && \
		info->precision < 0)
		ft_padding(buff, info, ft_padlen(info, len, i, 1));
	ft_precision_int(buff, info, len);
	if (n || info->precision)
		if (!(ft_putbuffer(buff, &(value[(sign[0] == '-' ? 1 : 0)]), len)))
			exit(-1);
	if (ft_strchr(info->flags, '-'))
		ft_padding(buff, info, ft_padlen(info, len, i, 1));
}
