/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:15:22 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 21:02:17 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_;
	const char			*src_;
	size_t				i;

	i = 0;
	src_ = src;
	dst_ = dst;
	while (i < n)
	{
		dst_[i] = src_[i];
		i++;
	}
	return (dst);
}
