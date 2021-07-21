/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaeletc <rafaeletc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:11:06 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/21 07:14:47 by rafaeletc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strtrunc(const char *str, char c);
char		*ft_getline(const char *str);

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buf;
	ssize_t		file;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !buf)
		return (NULL);
	if (cache && ft_strchr(cache, '\n'))
		cache = ft_strtrunc(cache, '\n');
	else
		cache = NULL;
	file = read(fd, buf, BUFFER_SIZE);
	while (file > 0)
	{
		buf[file] = '\0';
		cache = ft_strjoin(cache, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		free(buf);
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		file = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_getline(cache));
}

static char	*ft_strtrunc(const char *str, char c)
{
	size_t	size;

	if (!str)
		return (NULL);
	size = 0;
	while (*str++ != c)
		++size;
	return ((char *)str);
}

char	*ft_getline(const char *str)
{
	size_t	size;
	char	*tmp;

	if (!str)
		return (NULL);
	size = 0;
	if (!ft_strchr(str, '\n'))
	{
		str = ft_strjoin(str, "\n");
		return ((char *)str);
	}
	else
	{
		while (str[size++] != '\n')
			;
		tmp = malloc(sizeof(char) * (size + 1));
		ft_strlcpy(tmp, str, size + 1);
		return (tmp);
	}
}
