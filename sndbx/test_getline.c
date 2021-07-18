/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:31 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/17 19:45:13 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define MAXLINE 1000

int		ft_getline(char line[], int maxline);
void	ft_copy(char to[], char from[]);

int	main(void)
{
	int		len;
	int		max;
	char	line[MAXLINE];
	char	longest[MAXLINE];

	max = 0;
	while ((len = ft_getline(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			ft_copy(longest, line);
		}
	}
	if (max > 0)
		printf("%s", longest);
	return (0);
}

int	ft_getline(char s[], int lim)
{
	int	c;
	int	i;

	for (i=0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return (i);
}

void	ft_copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
