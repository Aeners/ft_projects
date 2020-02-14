/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:40:29 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/06 17:40:30 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char			*s_;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(s_ = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	while (s[i])
	{
		s_[i] = f(s[i]);
		i++;
	}
	s_[i] = '\0';
	return (s_);
}
