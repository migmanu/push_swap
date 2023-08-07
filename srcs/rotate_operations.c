/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:42:36 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/07 20:13:58 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack **stk_a, int toggle)
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
		write(1, "ra\n", 3);
}

void	do_rb(t_stack **stk_a, int toggle)
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
		write(1, "rb\n", 3);
}

void	do_rr(t_stack **stk_a, t_stack **stk_b, int toggle)
{
	do_ra(stk_a, 0);
	do_rb(stk_b, 0);
	if (toggle == 1)
		write(1, "rr\n", 3);
}

int	main(void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	stk_a = tst_make_stack(4);
	stk_b = tst_make_stack(4);
	//do_ra(&stk_a, 1);
	//do_rb(&stk_b, 1);
	//do_rr(&stk_a, &stk_b, 0);
	printf("\nstack A\n");
	tst_print_stack(&stk_a);
	printf("\nstack B\n");
	tst_print_stack(&stk_b);
	return (0);
}
