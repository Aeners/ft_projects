/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AL <AL@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:23:47 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/12 16:38:57 by AL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_percent(t_buff *buff, t_type *info)
{
	if (ft_strchr(info->flags, '-'))
	{
		if (!(ft_putbuffer(buff, &info->conv, 1)))
			exit(-1);
		ft_padding(buff, info, 1);
	}
	else
	{
		ft_padding(buff, info, 1);
		if (!(ft_putbuffer(buff, &info->conv, 1)))
			exit(-1);
	}
}
