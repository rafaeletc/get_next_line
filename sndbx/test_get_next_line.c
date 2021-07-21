/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:01:10 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/21 05:21:20 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test4(void);

int	main(void)
{
	int		fd;
	int		i;

	fd = open("gnlTester/files/big_line_no_nl", O_RDONLY, 0);
	i = 0;
	while (i++ < 9)
		printf("%s", get_next_line(fd));
	/*fd = open("sndbx/file1", O_RDONLY, 0);
	i = 0;
	printf("file1\n");
	while (++i <= 3)
		get_next_line(fd);*/
	return (0);
}

void	test4(void)
{
	int	fd;
	int	i;

	fd = open("sndbx/file1", O_RDONLY, 0);
	i = 0;
	printf("file1\n");
	while (++i <= 3)
		printf("%s", get_next_line(fd));
	fd = open("sndbx/file2", O_RDONLY, 0);
	i = 0;
	printf("\nfile2\n");
	while (++i <= 9)
		printf("%s", get_next_line(fd));
	fd = open("sndbx/file3", O_RDONLY, 0);
	i = 0;
	printf("\nfile3\n");
	while (++i <= 9)
		printf("%s", get_next_line(fd));
	fd = open("sndbx/file4", O_RDONLY, 0);
	i = 0;
	printf("\nfile4\n");
	while (++i <= 9)
		printf("%s", get_next_line(fd));
}
