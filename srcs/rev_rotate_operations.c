/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:42:36 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/07 19:40:05 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack **stk_a)
{
	t_stack	*last;
	t_stack	*new_last;

	if (!*stk_a || !(*stk_a)->next)
	{
		printf("nope\n");
		return ;
	}
	last = ft_lstlast(*stk_a);
	new_last = *stk_a;
	while (new_last->next != last)
		new_last = new_last->next;
	new_last->next = NULL;
	last->next = *stk_a;
	*stk_a = last;
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stk_a)
{
	t_stack	*last;
	t_stack	*new_last;

	if (!*stk_a || !(*stk_a)->next)
	{
		printf("nope\n");
		return ;
	}
	last = ft_lstlast(*stk_a);
	new_last = *stk_a;
	while (new_last->next != last)
		new_last = new_last->next;
	new_last->next = NULL;
	last->next = *stk_a;
	*stk_a = last;
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stk_a, t_stack **stk_b)
{
	do_rra(stk_a);
	do_rrb(stk_b);
	write(1, "rrr\n", 4);
}
/*
int	main(void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	stk_a = tst_make_stack(4);
	stk_b = tst_make_stack(4);
	//do_rra(&stk_a);
	//do_rrb(&stk_b);
	do_rrr(&stk_a, &stk_b);
	printf("\nstack A\n");
	tst_print_stack(&stk_a);
	printf("\nstack B\n");
	tst_print_stack(&stk_b);
	return (0);
}*/
