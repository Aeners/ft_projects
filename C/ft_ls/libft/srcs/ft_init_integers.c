/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:23:42 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/23 15:23:53 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_init_integers(const int nb, ...)
{
	int			i;
	int			*var;
	va_list		args;

	i = 0;
	va_start(args, nb);
	while (i < nb)
	{
		var = va_arg(args, int*);
		*var = 0;
		i++;
	}
	va_end(args);
}
