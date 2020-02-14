/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AL <AL@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:35:10 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/12 17:06:58 by AL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_padding(t_buff *buff, t_type *info, long long len)
{
	while (len < info->padding)
	{
		if (ft_strchr(info->flags, '0') && !(ft_strchr(FT_PRINTF_INT, \
			info->conv) && info->precision > 0) && \
			!(ft_strchr(info->flags, '-')))
		{
			if (!(ft_putbuffer(buff, "0", 1)))
				exit(-1);
		}
		else
		{
			if (!(ft_putbuffer(buff, " ", 1)))
				exit(-1);
		}
		len++;
	}
}

void		ft_precision_int(t_buff *buff, t_type *info, \
			long long len)
{
	while (len < info->precision)
	{
		if (!(ft_putbuffer(buff, "0", 1)))
			exit(-1);
		len++;
	}
}
