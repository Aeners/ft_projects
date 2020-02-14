/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:35:10 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/18 16:33:26 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
