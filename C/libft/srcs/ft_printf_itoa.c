/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:43:39 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/18 16:33:35 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int			ft_nbrlen(unsigned long long nbr, unsigned long long base)
{
	int			i;

	i = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

static void			baserot(char *value)
{
	int			i;

	i = 0;
	while (value[i])
	{
		if (value[i] > '9')
			value[i] = 'A' + value[i] - '9' - 1;
		i++;
	}
}

static void			itoa_base(unsigned long long n, unsigned long long base,
					char *value)
{
	int			i;
	int			len;

	i = 1;
	len = ft_nbrlen(n, base);
	while (n >= base)
	{
		value[len - i] = n % base + '0';
		n /= base;
		i++;
	}
	value[len - i] = n % base + '0';
}

void				ft_printf_itoa(long long n, int base, char *value)
{
	ft_bzero(value, 100);
	if (base == 10 && n < 0)
	{
		if (n < -9223372036854775807)
			ft_strcpy(value, "-9223372036854775808");
		else
		{
			value[0] = '-';
			itoa_base(-n, base, value + 1);
		}
	}
	else if (base == -10)
		itoa_base(n, -base, value);
	else
		itoa_base(n, base, value);
	if (base > 10)
		baserot(value);
}
