/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:24:35 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/06 16:24:36 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*memory;
	size_t	i;

	i = 0;
	if (!(memory = (void *)malloc(size)))
		return (NULL);
	else
	{
		ft_memset(memory, 0, size);
		return (memory);
	}
}
