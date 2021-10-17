/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:01:10 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/17 15:53:06 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test4(void);
void	lusiadas(void);

int	main(void)
{
	printf("Arquivos aleatórios:\n");
	test4();
	printf("\nLusiadas:\n");
	lusiadas();
	return (0);
}

void	lusiadas(void)
{
	int	fd;
	int	i;

	fd = open("sndbx/lusiadas.txt", O_RDONLY, 0);
	i = 0;
	while (i++ < 30)
		printf("%s", get_next_line(fd));
}

void	test4(void)
{
	int	fd;
	int	i;

	fd = open("sndbx/file1", O_RDONLY, 0);
	i = 0;
	while (++i <= 3)
		printf("%s", get_next_line(fd));
	fd = open("sndbx/file2", O_RDONLY, 0);
	i = 0;
	while (++i <= 9)
		printf("%s", get_next_line(fd));
	fd = open("sndbx/file3", O_RDONLY, 0);
	i = 0;
	while (++i <= 9)
		printf("%s", get_next_line(fd));
	fd = open("sndbx/file4", O_RDONLY, 0);
	i = 0;
	while (++i <= 9)
		printf("%s", get_next_line(fd));
	fd = open("sndbx/file5", O_RDONLY, 0);
	i = 0;
	while (++i <= 4)
		printf("%s", get_next_line(fd));
}
