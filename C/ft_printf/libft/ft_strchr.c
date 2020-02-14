/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:36:52 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/04 14:36:53 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		c_;
	size_t				i;

	i = 0;
	c_ = c;
	while (s[i] && s[i] != c_)
		i++;
	if (s[i] == c_)
		return ((char *)s + i);
	else
		return (NULL);
}
