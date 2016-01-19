/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:54:12 by asalama           #+#    #+#             */
/*   Updated: 2016/01/19 19:11:06 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_gnl;
{
	int		fd;
	char	*mem;
}				t_gnl;

int		get_next_line(int const fd, char **line);

#endif
