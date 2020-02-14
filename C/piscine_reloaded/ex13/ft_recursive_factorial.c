/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:26:58 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/02 14:26:59 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int		negative;

	negative = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	if (nb > 1)
		nb *= ft_recursive_factorial(nb - 1);
	if (negative == 1)
		return (-nb);
	return (nb);
}
