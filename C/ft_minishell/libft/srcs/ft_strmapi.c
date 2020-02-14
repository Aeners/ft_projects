/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:50:06 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 21:04:23 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if (!(s_ = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	while (s[i])
	{
		s_[i] = f(i, s[i]);
		i++;
	}
	s_[i] = '\0';
	return (s_);
}
