/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:01:10 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/19 01:26:46 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*buf1;
	char	*buf2;
	char	*buf3;
	char	*buf4;

	fd = open("/home/rafaeletc/Code/42/get_next_line/sndbx/file1", O_RDONLY, 0);
	buf1 = get_next_line(fd);
	printf("%s", buf1);
	buf2 = get_next_line(fd);
	printf("%s", buf2);
	buf3 = get_next_line(fd);
	printf("%s", buf3);
	buf4 = get_next_line(fd);
	printf("%s", buf4);
	return (0);
}
