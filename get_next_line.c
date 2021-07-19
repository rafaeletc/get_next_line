/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:11:06 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/19 03:10:13 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_getline(int fd, char *buf, char **s)
{
	ssize_t	i;

	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		*s = ft_substr(buf, 0, i - 1);
		if (ft_strchr(buf, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	if (i == 0)
		*s = 0;
	free(buf);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !buf || read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	ft_getline(fd, buf, &s);
	return (s);
}
