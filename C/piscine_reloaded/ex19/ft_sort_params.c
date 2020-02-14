/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:12:46 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/02 16:12:47 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] && s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_params(int argc, char **argv)
{
	int i;

	i = 1;
	while (argc > 1)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
		argc--;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		param;
	char	*tmp;

	i = 1;
	while (i)
	{
		i = 0;
		param = 1;
		while (param < argc - 1)
		{
			if (ft_strcmp(argv[param], argv[param + 1]) > 0)
			{
				tmp = argv[param];
				argv[param] = argv[param + 1];
				argv[param + 1] = tmp;
				i = 1;
			}
			param++;
		}
	}
	ft_print_params(argc, argv);
	return (0);
}
