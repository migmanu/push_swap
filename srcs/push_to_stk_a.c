/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stk_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:28:20 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/13 19:48:53 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*get_previous_in_a(t_stk *stk, t_stk *node)
{
	t_stk	*curr;
	t_stk	*previous;

	if (node->nbr > (stk_get_max(stk))->nbr)
		return (stk_get_min(stk));
	previous = stk_get_max(stk);
	curr = stk;
	while (curr)
	{
		if ((curr->nbr > node->nbr) && (curr->nbr < previous->nbr))
			previous = curr;
		curr = curr->next;
	}
	printf("prev node is %ld\n", previous->nbr);
	return (previous);
}

void	push_to_stk_a(t_stk **stk_a, t_stk **stk_b)
{
	printf("push_to_stk_a init\n");
	t_stk	*max_b;
	t_stk	*prev;
	int		sync;
	int		unsync;

	if (!*stk_b)
		return ;
	while (*stk_b)
	{
		max_b = stk_get_max(*stk_b);
		prev = get_previous_in_a(*stk_a, max_b);
		sync = get_sync_cst(*stk_a, *stk_b, prev, max_b);
		unsync = get_unsync_cst(*stk_a, *stk_b, prev, max_b);
		if (sync < unsync)
		{
			printf("use sync\n");
			sync_to_top(stk_a, stk_b, prev, max_b);
		}
		else
		{
			printf("use unsync\n");
			unsync_to_top(stk_a, stk_b, prev, max_b);
		}
		printf("push\n");
		printf("stk_a\n");
		tst_print_stk(*stk_a);
		printf("stk_b\n");
		tst_print_stk(*stk_b);
		write(1, "pa\n", 3);
		push(stk_b, stk_a);
	}
}


int	main(void)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	int		arr1[] = {3, 14, 37};
	int		arr2[] = {44, 21, 9};
	stk_a = tst_make_arr_stk(arr1, 3);
	stk_b = tst_make_arr_stk(arr2, 3);
	printf("Original stacks\n");
	printf("A\n");
	tst_print_stk(stk_a);
	printf("B\n");
	tst_print_stk(stk_b);
	push_to_stk_a(&stk_a, &stk_b);
	printf("Resulting stacks\n");
	printf("A\n");
	tst_print_stk(stk_a);
	printf("B\n");
	tst_print_stk(stk_b);
	return (0);
}
