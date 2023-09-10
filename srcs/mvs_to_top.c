/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvs_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:16:28 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/10 18:45:31 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*rotate(t_stk *stk)
{
	t_stk	*last;
	t_stk	*buf;

	if (!stk || !stk->next)
		return (NULL);
	buf = stk;
	stk = stk->next;
	last = stk_get_last(buf);
	buf->next = NULL;
	last->next = buf;
	return (stk);
}

t_stk	*rev_rotate(t_stk *stk)
{
	t_stk	*last;
	t_stk	*buf;

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

int	rot_to_top(t_stk *(*f) (t_stk *), t_stk *stk, t_stk *node)
{
	t_stk	*first;
	int		result;

	printf("rot init first: %ld node: %ld\n", stk->nbr, node->nbr);
	first = stk;
	tst_print_stk(first);
	result = 0;
	while (first && (first->nbr != node->nbr))
	{
		first = f(first);
		result += 1;
	}
	printf("result: %d\n", result);
	tst_print_stk(first);
	return (result);
}
/*
int	main(void)
{
	t_stk	*stk;

	stk = tst_make_stack(5, 98, 1);
	tst_print_stk(stk);
	t_stk *min = stk_get_min(stk);
	rot_to_top(rotate, stk, min);
	return (0);
}*/
