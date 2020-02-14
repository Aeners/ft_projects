/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:38:11 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/03 18:38:12 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		c_;
	unsigned char		*src_;
	unsigned char		*dst_;
	size_t				i;

	if (dst == src)
		return (dst);
	i = 0;
	c_ = (unsigned char)c;
	src_ = (unsigned char *)src;
	dst_ = (unsigned char *)dst;
	while (i < n)
	{
		dst_[i] = src_[i];
		if (dst_[i] == c_)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
