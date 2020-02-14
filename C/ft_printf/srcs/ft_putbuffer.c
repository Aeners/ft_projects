/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:10:08 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 17:04:27 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_putbuffer(t_buff *buff, void *adding, size_t size)
{
	int			diff;
	long long	i;

	i = 0;
	while (BUFF_SIZE - buff->index < (int)size)
	{
		diff = BUFF_SIZE - buff->index;
		ft_memcpy(&(buff->content[buff->index]), &(adding[i]), diff);
		size -= diff;
		i += diff;
		buff->index += diff;
		buff->ret += diff;
		if (write(1, buff->content, buff->index) < 0)
			return (0);
		buff->index = 0;
	}
	ft_memcpy(&(buff->content[buff->index]), &(adding[i]), size);
	buff->index += size;
	buff->ret += size;
	return (1);
}

int				ft_print_buff(t_buff *buff)
{
	if (write(1, buff->content, buff->index) < 0)
		return (0);
	return (1);
}
