/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:11:06 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/16 18:01:54 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char **buf, char **cache);

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buf;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!cache)
		cache = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	result = ft_getline(fd, &buf, &cache);
	free(buf);
	return (result);
}

char	*ft_getline(int fd, char **buf, char **cache)
{
	ssize_t	file;
	size_t	size;
	char	*tmp;
	char	*ret;

	file = read(fd, *buf, BUFFER_SIZE);
	while (file > 0)
	{
		(*buf)[file] = '\0';
		*cache = ft_strjoin(*cache, *buf);
		if (ft_strchr(*buf, '\n'))
			break ;
		file = read(fd, *buf, BUFFER_SIZE);
	}
	size = 0;
	while ((*cache)[size] != '\n')
		size++;
	tmp = *cache;
	ret = ft_substr(tmp, 0, (size + 1));
	*cache = ft_strdup(&(*cache)[size + 1]);
	free(tmp);
	return (ret);
}
