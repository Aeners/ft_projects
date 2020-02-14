/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:49:01 by AL                #+#    #+#             */
/*   Updated: 2017/01/18 16:35:06 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		ft_type(t_buff *buff, t_type info, va_list args)
{
	if (!(info.conv))
		return (0);
	else if (ft_strchr(FT_PRINTF_INT, info.conv))
		ft_int(buff, &info, va_arg(args, long long));
	else if (info.conv == 's')
		ft_string(buff, &info, va_arg(args, wchar_t *));
	else if (info.conv == 'c')
		ft_char(buff, &info, va_arg(args, wchar_t));
	else if (info.conv == 'p')
		ft_ptrhexa(buff, &info, va_arg(args, unsigned long));
	else
		ft_percent(buff, &info);
	return (1);
}

static int		ft_flags(const char *restrict format, int *i, t_type *info, \
				int boolean)
{
	int			flags_count;

	*i += (boolean ? 1 : 0);
	flags_count = ft_strlen(info->flags);
	while (format[*i] && \
		ft_strchr((boolean ? FT_PRINTF_FLAGS : FT_PRINTF_LENGTH), format[*i]))
	{
		if (!(ft_strchr(info->flags, format[*i])))
			info->flags[(flags_count)++] = format[*i];
		if ((format[*i] == 'h' || format[*i] == 'l') && (format[*i] == \
			format[*i + 1]) && (ft_strchrn(info->flags, format[*i]) < 2))
			info->flags[(flags_count)++] = format[*i];
		*i += 1;
	}
	if (!boolean)
	{
		info->conv = format[(*i)++];
		if (ft_strchr(FT_PRINTF_L, info->conv))
		{
			info->flags[flags_count] = 'l';
			info->conv = ft_tolower(info->conv);
		}
	}
	return (flags_count);
}

static void		ft_precision(const char *restrict format, int *i, t_type *info)
{
	info->precision = -1;
	if (format[*i] == '.')
	{
		*i += 1;
		info->precision = ft_atoll(&format[*i]);
		while (ft_isdigit(format[*i]) || format[*i] == '-')
			*i += 1;
	}
}

static t_type	ft_info(const char *restrict format, int *i)
{
	t_type		info;
	int			flags_count;

	ft_bzero(&info, sizeof(t_type));
	flags_count = ft_flags(format, i, &info, 1);
	if (ft_isdigit(format[*i]))
	{
		info.padding = ft_atoll(&format[*i]);
		while (ft_isdigit(format[*i]))
			*i += 1;
	}
	ft_precision(format, i, &info);
	ft_flags(format, i, &info, 0);
	return (info);
}

int				ft_printf(const char *restrict format, ...)
{
	int			i;
	t_buff		buff;
	va_list		args;

	va_start(args, format);
	i = 0;
	buff.index = 0;
	buff.ret = 0;
	ft_bzero(buff.content, BUFF_SIZE);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(ft_type(&buff, ft_info(format, &i), args)))
				break ;
		}
		else if (!(ft_putbuffer(&buff, (void *)&format[i++], 1)))
			return (-1);
	}
	if (!(ft_print_buff(&buff)))
		return (-1);
	va_end(args);
	return (buff.ret);
}
