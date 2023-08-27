/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvs_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:16:28 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/27 17:24:54 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate(t_stack *stk)
{
	t_stack	*last;
	t_stack	*buf;

	if (!stk || !stk->next)
		return (NULL);
	buf = stk;
	stk = stk->next;
	last = stk_get_last(buf);
	buf->next = NULL;
	last->next = buf;
	return (stk);
}

t_stack	*rev_rotate(t_stack *stk)
{
	t_stack	*last;
	t_stack	*buf;

	if (!stk || !stk->next)
		return (NULL);
	last = stk_get_last(stk);
	buf = stk;
	while (buf->next != last)
		buf = buf->next;
	buf->next = NULL;
	last->next = stk;
	stk = last;
	return (stk);
}

int	rot_to_top(t_stack *(*f) (t_stack *), t_stack *stk, t_stack *node)
{
	t_stack	*first;
	int	result;

	printf("rot init first: %ld node: %ld\n", stk->nbr, node->nbr);
	first = stk;
	tst_print_stack(first);
	result = 0;
	while (first && (first->nbr != node->nbr))
	{
		first = f(first);
		result += 1;
	}
	printf("result: %d\n", result);
	tst_print_stack(first);
	return (result);
}
/*
int	main(void)
{
	t_stack	*stk;

	stk = tst_make_stack(5, 98, 1);
	tst_print_stack(stk);
	t_stack *min = stk_get_min(stk);
	rot_to_top(rotate, stk, min);
	return (0);
}*/
