/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:23:11 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/17 14:51:12 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_minus(t_buff *buff, t_type *info,
				unsigned long p)
{
	char		ptr[100];

	ft_bzero(ptr, 100);
	ft_printf_itoa(p, 16, ptr);
	ft_strtolower(ptr);
	if (!(ft_putbuffer(buff, "0x", 2)))
		exit(-1);
	if (p || info->precision)
	{
		if (!(ft_putbuffer(buff, ptr, ft_strlen(ptr))))
			exit(-1);
	}
	ft_padding(buff, info, ft_strlen(ptr) + 2);
}

void			ft_ptrhexa(t_buff *buff, t_type *info,
				unsigned long p)
{
	char		ptr[100];

	if (ft_strchr(info->flags, '-'))
		ft_minus(buff, info, p);
	else
	{
		ft_bzero(ptr, 100);
		ft_printf_itoa(p, 16, ptr);
		ft_strtolower(ptr);
		if (!(ft_strchr(info->flags, '0')))
			ft_padding(buff, info, ft_strlen(ptr) + 2);
		if (!(ft_putbuffer(buff, "0x", 2)))
			exit(-1);
		if (ft_strchr(info->flags, '0'))
			ft_padding(buff, info, ft_strlen(ptr) + 2);
		if (p || info->precision)
		{
			if (!(ft_putbuffer(buff, ptr, ft_strlen(ptr))))
				exit(-1);
		}
	}
}
