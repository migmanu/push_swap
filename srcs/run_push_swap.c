/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:26:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/13 18:50:51 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates stk_b and pushes first two nodes in stk_b into it
t_stk	*push_two(t_stk **stk_a)
{
	t_stk	*stk_b;

	if (stk_cnt_nds(*stk_a) > 3)
	{
		stk_b = *stk_a;
		*stk_a = (*stk_a)->next;
		stk_b->next = NULL;
	}
	if (stk_cnt_nds(*stk_a) > 3)
	{
		push(stk_a, &stk_b);
	}
	return (stk_b);
}

// Takes care of pushing the cheapest node from stk_a
// into stk_b
void push_to_stk_b(t_stk **stk_a, t_stk **stk_b)
{
	printf("push_to_stk_b init\n");
	t_stk	*cheapest;
	t_stk	*prev;
	int		sync;
	int		unsync;

	while (stk_cnt_nds(*stk_a) > 3)
	{
		cheapest = find_cheapest(*stk_a, *stk_b);
		prev = get_previous(*stk_b, cheapest);
		sync = get_sync_cst(*stk_a, *stk_b, cheapest, prev);
		unsync = get_unsync_cst(*stk_a, *stk_b, cheapest, prev);
		if (sync < unsync)
		{
			printf("use sync\n");
			sync_to_top(stk_a, stk_b, cheapest, prev);
		}
		else
		{
			printf("use unsync\n");
			unsync_to_top(stk_a, stk_b, cheapest, prev);
		}
		printf("push\n");
		printf("stk_a\n");
		tst_print_stk(*stk_a);
		printf("stk_b\n");
		tst_print_stk(*stk_b);
		push(stk_a, stk_b);
	}
}

t_bool	run_push_swap(t_stk **stk_a)
{
	t_stk	*stk_b;

	if (!*stk_a)
		return (false);
	stk_b = push_two(stk_a);
	push_to_stk_b(stk_a, &stk_b);
	solve_three(stk_a);
	return (true);
}

int	main(void)
{
	t_stk	*stk_a;

	stk_a = tst_make_stack(6, 543, 1);
	//stk_b = tst_make_stack(2, 53, 1);
	run_push_swap(&stk_a);
	return (0);
}
