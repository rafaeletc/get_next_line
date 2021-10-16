/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:01:10 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/16 17:55:12 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test4(void);
void	gnlTester(void);

int	main(void)
{
	int		fd;
	int		i;

	fd = open("sndbx/lusiadas.txt", O_RDONLY, 0);
	i = 0;
	while (i++ < 30)
		printf("%s", get_next_line(fd));
	test4();
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
	fd = open("sndbx/file5", O_RDONLY, 0);
	i = 0;
	printf("\nfile5\n");
	while (++i <= 4)
		printf("%s", get_next_line(fd));
}

void	gnlTester(void)
{
	int	fd;
	int	i;

	printf("\n41_no_nl\n");
	fd = open("gnlTester/files/41_no_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("\n41_with_nl\n");
	fd = open("gnlTester/files/41_with_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("\n42_no_nl\n");
	fd = open("gnlTester/files/42_no_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("\n42_with_nl\n");
	fd = open("gnlTester/files/42_with_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("\n43_no_nl\n");
	fd = open("gnlTester/files/43_no_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("\n43_with_nl\n");
	fd = open("gnlTester/files/43_with_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("\nalternate_line_nl_no_nl\n");
	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY, 0);
	i = 0;
	while (i++ <= 9)
		printf("%s", get_next_line(fd));
	printf("\nalternate_line_nl_with_nl\n");
	fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDONLY, 0);
	i = 0;
	while (i++ <= 10)
		printf("%s", get_next_line(fd));
	printf("\nbig_line_no_nl\n");
	fd = open("gnlTester/files/big_line_no_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("\nbig_line_with_nl\n");
	fd = open("gnlTester/files/big_line_with_nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("\nempty\n");
	fd = open("gnlTester/files/", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("\nmultiple_line_with_nl\n");
	fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY, 0);
	i = 0;
	while (i++ <= 5)
		printf("%s", get_next_line(fd));
	printf("\nmultiple_line_no_nl\n");
	fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY, 0);
	i = 0;
	while (i++ <= 6)
		printf("%s", get_next_line(fd));
	printf("\nmultiple_nlx5\n");
	fd = open("gnlTester/files/multiple_nlx5", O_RDONLY, 0);
	i = 0;
	while (i++ <= 6)
		printf("%s", get_next_line(fd));
	printf("\nnl\n");
	fd = open("gnlTester/files/nl", O_RDONLY, 0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
