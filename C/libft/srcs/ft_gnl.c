/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:19:06 by arlecomt          #+#    #+#             */
/*   Updated: 2017/01/26 18:45:56 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_ct		*ft_create_list(t_list **lst, const int fd)
{
	t_ct		content;
	t_list		*lst_temp;

	if (fd < 0 || !lst)
		return (NULL);
	lst_temp = *lst;
	while (lst_temp)
	{
		if (((t_ct *)(lst_temp->content))->fd == fd)
			return (lst_temp->content);
		lst_temp = lst_temp->next;
	}
	content.fd = fd;
	if (!(content.r_line = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(lst_temp = ft_lstnew(&content, sizeof(content))))
	{
		free(content.r_line);
		return (NULL);
	}
	ft_lstadd(lst, lst_temp);
	return ((*lst)->content);
}

static int		ft_cut_cpy(char **line, char **r_line)
{
	char		*tmp;
	int			ret;

	ret = 0;
	if ((tmp = ft_strchr(*r_line, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strdup(*r_line)))
			return (-1);
		tmp++;
		ft_strcpy(*r_line, tmp);
		ret = 1;
	}
	else if (ft_strlen(*r_line))
	{
		if (!(*line = ft_strdup(*r_line)))
			return (-1);
		**r_line = '\0';
		ret = 1;
	}
	else if (!(*line = ft_strnew(0)))
		return (-1);
	return (ret);
}

static int		read_buffer(t_ct **content)
{
	char		curr_line[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	while (!ft_strchr((*content)->r_line, '\n'))
	{
		ft_bzero(curr_line, BUFF_SIZE + 1);
		if ((ret = read((*content)->fd, curr_line, BUFF_SIZE)) == -1)
			return (-1);
		if (!ret)
			return (0);
		tmp = (*content)->r_line;
		if (!((*content)->r_line = ft_strjoin((*content)->r_line, curr_line)))
			return (-1);
		free(tmp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_ct			*gnl_content;
	int				ret;

	if (BUFF_SIZE <= 0 || !line || !(gnl_content = ft_create_list(&lst, fd)))
		return (-1);
	if ((ret = read_buffer(&gnl_content)) == -1)
		return (-1);
	return (ft_cut_cpy(line, &(gnl_content->r_line)));
}
