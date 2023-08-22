/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:40:27 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/22 20:05:47 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack **stk_a, int toggle)
{
	t_stack	*second_node;

	if (!stk_a || !*stk_a || !(*stk_a)->next)
	{
		printf("nothing\n");
		return ;
	}
	second_node = *stk_a;
	*stk_a = (*stk_a)->next;
	second_node->next = (*stk_a)->next;
	(*stk_a)->next = second_node;
	if (toggle == 1)
		write(1, "sa\n", 3);
}

void	do_sb(t_stack **stk_b, int toggle)
{
	t_stack	*second_node;

	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	second_node = *stk_b;
	*stk_b = (*stk_b)->next;
	second_node->next = (*stk_b)->next;
	(*stk_b)->next = second_node;
	if (toggle == 1)
		write(1, "sb\n", 3);
}

void	do_ss(t_stack **stk_a, t_stack **stk_b)
{
	do_sa(stk_a, 0);
	do_sb(stk_b, 0);
}
/*
int	main (void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	stk_a = tst_make_stack(6);
	//do_sa(&stk_a);
	stk_b = tst_make_stack(5);
	//do_sb(&stk_b);
	do_ss(&stk_a, &stk_b);
	tst_print_stack(&stk_a);
	printf("\nnow B \n");
	tst_print_stack(&stk_b);
	return (0);
}*/
