/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:22:28 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/18 16:33:18 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_size_bin(int c)
{
	int		i;

	i = 0;
	if (c < 0)
		c *= -1;
	while (c >> i)
		i++;
	return (i);
}

static void	ft_unicode(wchar_t c, char *char_oct, int *i, int size)
{
	if (size > 7)
	{
		if (size > 11)
		{
			if (size > 16)
			{
				char_oct[(*i)++] = (((c >> 18) & 0b00000111) | 0b11110000);
				char_oct[(*i)++] = (((c >> 12) & 0b00111111) | 0b10000000);
			}
			else
				char_oct[(*i)++] = (((c >> 12) & 0b00011111) | 0b11100000);
			char_oct[(*i)++] = (((c >> 6) & 0b00111111) | 0b10000000);
		}
		else
			char_oct[(*i)++] = (((c >> 6) & 0b00011111) | 0b11000000);
		char_oct[(*i)++] = ((c & 0b00111111) | 0b10000000);
	}
	else
		char_oct[(*i)++] = (unsigned char)c;
}

void		ft_charadd(t_type *info, wchar_t c, char *char_oct, int *i)
{
	*i = 0;
	if (c < 0 || c > MAX_UNI)
		return ;
	else if (ft_strchr(info->flags, 'l'))
		ft_unicode(c, char_oct, i, ft_size_bin(c));
	else
		char_oct[(*i)++] = (unsigned char)c;
}

void		ft_char(t_buff *buff, t_type *info, wchar_t c)
{
	char		char_oct[5];
	int			i;

	ft_bzero(char_oct, 5);
	ft_charadd(info, c, char_oct, &i);
	if (ft_strchr(info->flags, '-'))
	{
		if (!(ft_putbuffer(buff, char_oct, i)))
			exit(-1);
		ft_padding(buff, info, i);
	}
	else
	{
		ft_padding(buff, info, i);
		if (!(ft_putbuffer(buff, char_oct, i)))
			exit(-1);
	}
}
