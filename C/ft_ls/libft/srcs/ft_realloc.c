/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:58:58 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 21:03:17 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_realloc(char *ptr, size_t size)
{
	char	*tmp;
	int		i;

	tmp = ptr;
	free(ptr);
	i = 0;
	if (!(ptr = (char *)malloc(size)))
		return (NULL);
	while (tmp[i])
	{
		ptr[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (ptr);
}
