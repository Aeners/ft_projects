/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:51:17 by AL                #+#    #+#             */
/*   Updated: 2017/01/13 21:01:14 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_atoll(const char *str)
{
	long long		nb;
	int				i;
	int				negative;

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
