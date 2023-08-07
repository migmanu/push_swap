/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:40:27 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/07 13:36:56 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack **stk_a)
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
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stk_b)
{
	t_stack	*second_node;
	
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	second_node = *stk_b;
	*stk_b = (*stk_b)->next;
	second_node->next = (*stk_b)->next;
	(*stk_b)->next = second_node;
	write(1, "sb\n", 3);
}

int	main (void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	stk_a = tst_make_stack(1);
	//do_sa(&stk_a);
	//tst_print_stack(&stk_a);
	printf("now B \n\n");
	stk_b = tst_make_stack(10);
	do_sa(&stk_b);
	tst_print_stack(&stk_b);
	return (0);
}
