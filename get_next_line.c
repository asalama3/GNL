/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:23 by asalama           #+#    #+#             */
/*   Updated: 2016/01/19 20:34:28 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list	*add_maillon(t_list *lst, int const fd)
{
	t_gnl	gnl;

	gnl.fd = fd;
	gnl.mem = ft_strnew(BUFF_SIZE);
	if (gnl.mem == NULL)
		return (NULL);
	ft_lstadd(&lst, ft_lstnew(&gnl, sizeof(gnl)));
}

t_list	*get_fd(t_list **lst, int const fd)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		if (fd == ptr->content->fd)
			return (ptr);
		ptr = ptr->next;
	}
	return (lst);
}

int		read_fd(t_list *lst, int const fd)
{
	int		ret;
	char	buf[BUFF_SIZE];
	char	*tmp;

	while (ft_strchr((lst->content)->mem, '\n') == NULL 

}

int		get_next_line(int const fd, char **line)
{
}




int	get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*m = NULL;
	int			ret;

	if ((BUFF_SIZE <= 0) || !line)
		return (-1);
	if (m == NULL)
		m = ft_strnew(0);
	ret = 1;
	while ((ft_strchr(m, '\n') == NULL) && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		m = ft_strjoin(m, buff);
	}
	if (ft_strchr(m, '\n'))
		*line = ft_strsub(m, 0, ft_strchr(m, '\n') - m + 1);
	else
		*line = ft_strdup(m);
	if (ret)
		line[0][ft_strlen(*line) - 1] = '\0';
	m = ft_strsub(m, ft_strchr(m, '\n') - m + 1, ft_strlen(ft_strchr(m, '\n')));
	return (ret == 0 ? 0 : 1);
}
