/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:24:35 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/24 16:30:30 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
