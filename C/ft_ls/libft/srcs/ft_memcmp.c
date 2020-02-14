/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:38:11 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/13 21:02:13 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*s1_;
	unsigned char		*s2_;
	size_t				i;

	i = 0;
	s1_ = (unsigned char *)s1;
	s2_ = (unsigned char *)s2;
	while (i < n && s1_[i] == s2_[i])
		i++;
	if (i == n)
		return (0);
	else
		return (s1_[i] - s2_[i]);
}
