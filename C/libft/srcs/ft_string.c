/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:21:46 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/18 16:36:16 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int			ft_ret_length(wchar_t *s, long long precision)
{
	int		len;
	int		size;
	int		max_len;

	len = 0;
	if (precision < 0)
		precision = ft_wcslen(s) * 4;
	while (*s && len <= precision)
	{
		max_len = len;
		size = ft_size_bin(*s);
		if (size > 16)
			len += 4;
		else if (size > 11)
			len += 3;
		else if (size > 7)
			len += 2;
		else
			len += 1;
		s++;
	}
	if (len <= precision)
		return (len);
	return (max_len);
}

static void			ft_wcharacter(t_buff *buff, t_type *info, wchar_t *s)
{
	int		i;
	int		len;
	int		size_char;
	char	char_oct[5];

	i = 0;
	size_char = 0;
	len = ft_ret_length(s, info->precision);
	if (!(ft_strchr(info->flags, '-')))
		ft_padding(buff, info, len);
	while (i < len)
	{
		ft_bzero(char_oct, 5);
		ft_charadd(info, *s, char_oct, &size_char);
		if (!(ft_putbuffer(buff, char_oct, size_char)))
			exit(-1);
		i += size_char;
		s++;
	}
	if (ft_strchr(info->flags, '-'))
		ft_padding(buff, info, len);
}

static void			ft_character(t_buff *buff, t_type *info, char *s)
{
	size_t		len;

	len = ft_strlen(s);
	if (info->precision >= 0)
		len = ((int)len < info->precision ? len : info->precision);
	if (ft_strchr(info->flags, '-'))
	{
		if (!(ft_putbuffer(buff, s, len)))
			exit(-1);
		ft_padding(buff, info, len);
	}
	else
	{
		ft_padding(buff, info, len);
		if (!(ft_putbuffer(buff, s, len)))
			exit(-1);
	}
}

void				ft_string(t_buff *buff, t_type *info, wchar_t *s)
{
	if (!s)
		ft_character(buff, info, "(null)");
	else
	{
		if (ft_strchr(info->flags, 'l'))
			ft_wcharacter(buff, info, s);
		else
			ft_character(buff, info, (char *)s);
	}
}
