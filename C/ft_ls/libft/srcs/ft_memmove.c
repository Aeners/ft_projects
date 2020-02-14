/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:51:01 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 21:02:24 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_;
	char	*dst_;
	size_t	i;

	i = -1;
	src_ = (char *)src;
	dst_ = (char *)dst;
	if (src_ < dst_)
		while ((int)--len >= 0)
			*(dst_ + len) = *(src_ + len);
	else
		while (++i < len)
			*(dst_ + i) = *(src_ + i);
	return (dst);
}
