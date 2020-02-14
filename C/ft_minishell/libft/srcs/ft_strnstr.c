/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:24:34 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 21:04:47 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	if (little[i] == '\0' && big[i] == '\0')
		return ((char *)(big));
	while (big[i] && i < len)
	{
		j = 0;
		k = i;
		while (big[i] == little[j] && little[j] && i < len)
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + (i - j)));
		else
			i = k;
		i++;
	}
	return (NULL);
}
