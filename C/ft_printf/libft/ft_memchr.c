/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:07:48 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/03 19:07:48 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*s_;

	i = -1;
	s_ = (char *)s;
	while (++i < n)
		if ((unsigned char)*(s_ + i) == (unsigned char)c)
			return (s_ + i);
	return (NULL);
}
