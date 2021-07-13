/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:02:04 by rde-lima          #+#    #+#             */
/*   Updated: 2021/07/13 20:00:16 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
