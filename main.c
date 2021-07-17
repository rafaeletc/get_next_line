/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:00:37 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/17 16:19:24 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	static_call(void)
{
	printf("Chamada estática c/ static_func()\n");
	static_func();
	static_func();
	static_func();
	static_func();
	static_func();
}

void	dynamic_call(void)
{
	printf("\nChamada dinâmica c/ dynamic_func()\n");
	dynamic_func();
	dynamic_func();
	dynamic_func();
	dynamic_func();
	dynamic_func();
}

int	main(void)
{
	int	fd;

	static_call();
	dynamic_call();
	fd = open("file3", O_RDONLY);
	printf("\nfd = %d\n", fd);
	return (0);
}
