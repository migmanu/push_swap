/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:33:07 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/07 17:57:02 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	rotate(t_stack **stk)
{
	t_stack	*last;
	t_stack	*buf;

	if (!*stk || !(*stk)->next)
		return (false);
	buf = *stk;
	*stk = (*stk)->next;
	last = stk_get_last(buf);
	buf->next = NULL;
	last->next = buf;
	return (true);
}

t_bool	rev_rotate(t_stack **stk)
{
	t_stack	*last;
	t_stack	*buf;

	if (!*stk || !(*stk)->next)
		return (false);
	last = stk_get_last(*stk);
	buf = *stk;
	while (buf->next != last)
		buf = buf->next;
	buf->next = NULL;
	last->next = *stk;
	*stk = last;
	return (true);
}

t_bool	sync_rotate(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !stk_b)
		return (false);
	if (rotate(stk_a) == false || rotate(stk_b) == false)
		return (false);
	return (true);
}

t_bool	sync_rev_rotate(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !stk_b)
		return (false);
	if (rev_rotate(stk_a) == false || rev_rotate(stk_b) == false)
		return (false);
	return (true);
}
/*
int	main(void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = tst_make_stack(4, 102, 1);
	stk_b = tst_make_stack(3, 82, 1);
	printf("stk a\n");
	tst_print_stack(stk_a);
	printf("stk b\n");
	tst_print_stack(stk_b);
	rotate(&stk_a);
	rotate(&stk_b);
	printf("ROTATE\n");
	printf("stk a\n");
	tst_print_stack(stk_a);
	printf("stk b\n");
	tst_print_stack(stk_b);
	sync_rotate(&stk_a, &stk_b);
	printf("SYNC ROTATE\n");
	printf("stk a\n");
	tst_print_stack(stk_a);
	printf("stk b\n");
	tst_print_stack(stk_b);
	rev_rotate(&stk_a);
	rev_rotate(&stk_b);
	printf("REV ROTATE\n");
	printf("stk a\n");
	tst_print_stack(stk_a);
	printf("stk b\n");
	tst_print_stack(stk_b);
	sync_rev_rotate(&stk_a, &stk_b);
	printf("SYNC REV ROTATE\n");
	printf("stk a\n");
	tst_print_stack(stk_a);
	printf("stk b\n");
	tst_print_stack(stk_b);
	return (0);
}*/
