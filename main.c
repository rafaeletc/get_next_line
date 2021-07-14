/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:00:37 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/13 22:21:58 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "get_next_line.h"

void	conv_lower(void)
{
	int	c;

	c = getchar();
	while (c != EOF)
		putchar(tolower(c));
}

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
	static_call();
	dynamic_call();
	conv_lower();
	return (0);
}
