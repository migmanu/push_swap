/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:26:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/14 19:03:19 by migmanu          ###   ########.fr       */
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
		write(1, "pb\n", 3);
	}
	if (stk_cnt_nds(*stk_a) > 3)
	{
		push(stk_a, &stk_b);
		write(1, "pb\n", 3);
	}
	return (stk_b);
}

// Function used to put stk_a in ascending order, afer runing
// push_to_stk_a.
void	order_stk_a(t_stk **stk_a, t_stk *min)
{
	if (get_rot_cost(*stk_a, min) < get_rev_rot_cost(*stk_a, min))
	{
		write_n_rotate(stk_a, min, 1);
	}
	else
	{
		write_n_rev_rotate(stk_a, min, 1);
	}
}

// Takes care of pushing the cheapest node from stk_a
// into stk_b
void	push_to_stk_b(t_stk **stk_a, t_stk **stk_b)
{
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
			sync_to_top(stk_a, stk_b, cheapest, prev);
		}
		else
		{
			unsync_to_top(stk_a, stk_b, cheapest, prev);
		}
		write(1, "pb\n", 3);
		push(stk_a, stk_b);
	}
}

t_bool	run_push_swap(t_stk **stk_a)
{
	t_stk	*stk_b;

	if (!*stk_a)
		return (false);
	if (stk_cnt_nds(*stk_a) == 3)
	{
		solve_three(stk_a);
		order_stk_a(stk_a, stk_get_min(*stk_a));
		free_stk(*stk_a);
		return (true);
	}
	stk_b = push_two(stk_a);
	push_to_stk_b(stk_a, &stk_b);
	solve_three(stk_a);
	push_to_stk_a(stk_a, &stk_b);
	order_stk_a(stk_a, stk_get_min(*stk_a));
	free_stk(stk_b);
	free_stk(*stk_a);
	return (true);
}
/*
int	main(void)
{
	t_stk	*stk_a;
	int	arr1[] = {6, 543, 1};

	stk_a = tst_make_stack(5, 543, 1);
	//stk_a = tst_make_arr_stk(arr1, 3);
	//stk_b = tst_make_stack(2, 53, 1);
	run_push_swap(&stk_a);
	return (0);
}*/
