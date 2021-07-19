/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:02:04 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/19 01:20:40 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
		++counter;
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*src;
	size_t	i;

	s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	src = (char *)s + start;
	i = 0;
	while (*src && i < len)
		s1[i++] = *src++;
	s1[i] = '\0';
	return (s1);
}
