/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:38:10 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/18 11:47:34 by rde-lima         ###   ########.fr       */
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
	return (0);
}

void	test4(void)
{
	int	fd[5];
	int	i;

	fd[0] = open("sndbx/file1", O_RDONLY, 0);
	fd[1] = open("sndbx/file2", O_RDONLY, 0);
	fd[2] = open("sndbx/file3", O_RDONLY, 0);
	fd[3] = open("sndbx/file4", O_RDONLY, 0);
	fd[4] = open("sndbx/file5", O_RDONLY, 0);
	i = 0;
	while (++i <= 3)
	{
		printf("fd[0]:\n%s", get_next_line(fd[0]));
		printf("fd[1]:\n%s", get_next_line(fd[1]));
		printf("fd[2]:\n%s", get_next_line(fd[2]));
		printf("fd[3]:\n%s", get_next_line(fd[3]));
		printf("fd[4]:\n%s", get_next_line(fd[4]));
	}
}
