/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:10:49 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/04 18:10:50 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		i;
	int		negative;

	i = 0;
	nb = 0;
	negative = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\r' || str[i] == '\f') && str[i])
		i++;
	if (str[i] == '-')
	{
		negative = 42;
		i++;
	}
	if (str[i] == '+' && negative == 0)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += (str[i] - 48) % 10;
		i++;
	}
	return ((negative == 42 ? -nb : nb));
}
