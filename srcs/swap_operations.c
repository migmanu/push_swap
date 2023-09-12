/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:42:10 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/12 19:52:08 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stk **stk)
{
	t_stk	*buf;

	buf = *stk;
	*stk = buf->next;
	buf->next = (*stk)->next;
	(*stk)->next = buf;
}
/*
int	main(void)
{
	t_stk	*stk;
	stk = tst_make_stack(4, 234, 1);
	tst_print_stk(stk);
	swap(&stk);
	printf("result\n");
	tst_print_stk(stk);
	return (0);
}*/
