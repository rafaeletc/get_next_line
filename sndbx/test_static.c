/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_static.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:00:37 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/17 18:49:23 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	static_func(void);
void	dynamic_func(void);
void	static_call(void);
void	dynamic_call(void);

int	main(void)
{
	static_call();
	dynamic_call();
	return (0);
}

/*
** Declaração da variável estática só inicializa uma vez durante a execução,
** independente da quantidade de vezes que for chamada. Aqui atribuo o valor 0
** (se não tivesse atribuido, seria esse valor, automagicamente).
** Parece que a norminette aceita declaração assim, não conferi a norma.
*/
void	static_func(void)
{
	static int	x = 0;

	++x;
	printf("%d\n", x);
}

/*
** Já uma variável não estática é inicializada toda vez que a função
** for chamada durante a execução.
*/
void	dynamic_func(void)
{
	int	x;

	x = 0;
	++x;
	printf("%d\n", x);
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
