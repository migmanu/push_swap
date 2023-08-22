/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:19:16 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/22 20:02:35 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack **stk_a, t_stack **stk_b, int toggle)
{
	t_stack	*buf;

	if (!*stk_a || !*stk_b)
		return ;
	buf = *stk_b;
	*stk_b = (*stk_b)->next;
	buf->next = *stk_a;
	*stk_a = buf;
	if (toggle == 1)
		write(1, "pa\n", 3);
}

void	do_pb(t_stack **stk_a, t_stack **stk_b, int toggle)
{
	t_stack	*buf;

	if (!*stk_a || !*stk_b)
		return ;
	buf = *stk_a;
	*stk_a = (*stk_a)->next;
	buf->next = *stk_b;
	*stk_b = buf;
	if (toggle == 1)
		write(1, "pb\n", 3);
}
/*
int	main (void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	stk_a = tst_make_stack(4);
	stk_b = tst_make_stack(4);
	do_pb(&stk_a, &stk_b);
	printf("\nstack A\n");
	tst_print_stack(&stk_a);
	printf("\nstack B\n");
	tst_print_stack(&stk_b);
	return (0);
}*/
