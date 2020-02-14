/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:01:48 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/02 14:01:49 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		negative;
	int		i;

	negative = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	i = nb;
	if (nb > 12)
		return (0);
	while (i > 1)
	{
		nb *= (i - 1);
		i--;
	}
	if (negative == 1)
		return (-nb);
	return (nb);
}
