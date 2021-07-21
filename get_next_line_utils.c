/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaeletc <rafaeletc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:02:04 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/21 07:17:55 by rafaeletc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		++len;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;
	size_t	length;

	if (!dest || !src)
		return (0);
	length = ft_strlen(src);
	if (size == 0)
		return (length);
	counter = 0;
	while (counter < size - 1 && counter < length)
	{
		dest[counter] = src[counter];
		++counter;
	}
	dest[counter] = '\0';
	return (length);
}

char	*ft_strdup(const char *str1)
{
	size_t		counter;
	char		*str;

	if (!str1)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(str1) + 1));
	counter = 0;
	while (*str1 != '\0')
		str[counter++] = *str1++;
	str[counter] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	size = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (*s1 != '\0')
		str[size++] = *s1++;
	while (*s2 != '\0')
		str[size++] = *s2++;
	str[size] = '\0';
	return (str);
}
