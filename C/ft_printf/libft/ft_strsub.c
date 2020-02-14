/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:59:23 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/06 17:59:24 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s_;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(s_ = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		s_[i] = s[start];
		i++;
		start++;
	}
	s_[i] = '\0';
	return (s_);
}
