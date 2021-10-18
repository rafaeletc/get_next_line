/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:02:04 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/18 00:36:51 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(int fd, char **buf, char **cache);
ssize_t	ft_readfile(int fd, char **buf, char **cache);
char	*ft_writecache(char **cache);

char	*get_next_line(int fd)
{
	static char	*cache[OPEN_MAX];
	char		*buf;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!cache[fd])
		cache[fd] = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	res = ft_getline(fd, &buf, &cache[fd]);
	free(buf);
	buf = NULL;
	return (res);
}

char	*ft_getline(int fd, char **buf, char **cache)
{
	ssize_t	size;
	char	*res;

	size = ft_readfile(fd, buf, cache);
	if (size <= 0 && !**cache)
	{
		free(*cache);
		*cache = NULL;
		return (NULL);
	}
	if (ft_strchr(*cache, '\n'))
		return (ft_writecache(cache));
	res = ft_strdup(*cache);
	free(*cache);
	*cache = NULL;
	return (res);
}

ssize_t	ft_readfile(int fd, char **buf, char **cache)
{
	ssize_t	res;
	char	*tmp;

	res = 1;
	while (!ft_strchr(*cache, '\n') && res)
	{
		res = read(fd, *buf, BUFFER_SIZE);
		if (res < 0)
			return (res);
		(*buf)[res] = '\0';
		tmp = *cache;
		*cache = ft_strjoin(tmp, *buf);
		free(tmp);
		tmp = NULL;
	}
	return (res);
}

char	*ft_writecache(char **cache)
{
	ssize_t	size;
	char	*res;
	char	*tmp;

	size = 0;
	while ((*cache)[size] != '\n' && (*cache)[size] != '\0')
		++size;
	if ((*cache)[size] == '\n')
		++size;
	tmp = *cache;
	res = ft_substr(tmp, 0, size);
	*cache = ft_strdup(&(*cache)[size]);
	free(tmp);
	tmp = NULL;
	return (res);
}
