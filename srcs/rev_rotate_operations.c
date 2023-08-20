/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:42:36 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/20 22:28:34 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack **stk_a, int toggle)
{
	t_stack	*last;
	t_stack	*buf;

	if (!*stk_a || !(*stk_a)->next)
		return ;
	last = ft_lstlast(*stk_a);
	buf = *stk_a;
	while (buf->next != last)
		buf = buf->next;
	buf->next = NULL;
	last->next = *stk_a;
	*stk_a = last;
	if (toggle == 1)
		write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stk_a, int toggle)
{
	t_stack	*last;
	t_stack	*buf;

	if (!*stk_a || !(*stk_a)->next)
		return ;
	last = ft_lstlast(*stk_a);
	buf = *stk_a;
	while (buf->next != last)
		buf = buf->next;
	buf->next = NULL;
	last->next = *stk_a;
	*stk_a = last;
	if (toggle == 1)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stk_a, t_stack **stk_b, int toggle)
{
	do_rra(stk_a, 0);
	do_rrb(stk_b, 0);
	if (toggle == 1)
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
	do_rrr(&stk_a, &stk_b, 0);
	printf("\nstack A\n");
	tst_print_stack(&stk_a);
	printf("\nstack B\n");
	tst_print_stack(&stk_b);
	return (0);
}*/
