/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getline_term_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:00:37 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/17 18:47:19 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE

int	main(int argc, char *argv[])
{
	FILE	*stream;
	char	*line;
	int		line_count;
	size_t	len;
	ssize_t	nread;

	line = NULL;
	len = 0;
	line_count = 0;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	nread = getline(&line, &len, stream);
	while (nread != -1)
	{
		++line_count;
		printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s",
			line_count, nread, len, line);
		nread = getline(&line, &len, stream);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
