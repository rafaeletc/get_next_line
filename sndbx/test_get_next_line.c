/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:01:10 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/18 11:51:22 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	lusiadas(void);

int	main(void)
{
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
