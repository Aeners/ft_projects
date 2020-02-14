/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:08:29 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/04 15:08:30 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	c_;

	c_ = c;
	i = 0;
	while (s[i])
		i++;
	while (i > 0 && s[i] != c_)
		i--;
	if (s[i] == c_)
		return ((char *)s + i);
	else
		return (NULL);
}
