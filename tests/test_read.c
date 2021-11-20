/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:31:19 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/18 11:53:07 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*buf;

	buf = malloc(sizeof(char) * 16);
	fd = open("sndbx/lusiadas.txt", O_RDONLY, 0);
	i = 0;
	while (i < 99)
	{
		read(fd, buf, 16);
	}
}
