/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:11:06 by rde-lima          #+#    #+#             */
/*   Updated: 2021/11/16 14:19:56 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_getline(int fd, char **buf, char **cache);
static ssize_t	ft_readfile(int fd, char **buf, char **cache);
static char		*ft_writecache(char **cache);

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buf;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!cache)
		cache = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	res = ft_getline(fd, &buf, &cache);
	free(buf);
	buf = NULL;
	return (res);
}

static char	*ft_getline(int fd, char **buf, char **cache)
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

static ssize_t	ft_readfile(int fd, char **buf, char **cache)
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

static char	*ft_writecache(char **cache)
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
