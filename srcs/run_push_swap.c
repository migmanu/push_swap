/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:26:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/10 18:42:24 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push just two nodes from stk_a to stk_b, as long as
// theres at least 3 nodes remaining at stk_a
void	push_two(t_stack **stk_a, t_stack **stk_b)
{
	if (stk_cnt_nds(*stk_a) > 3)
		push(stk_a, stk_b);
	if (stk_cnt_nds(*stk_a) > 3)
		push(stk_a, stk_b);
}

// Decides wether rotation or rev rotation is cheaper for a sync move.
// Returns true if rotations is cheaper and false if rev_rotation is cheaper
t_bool	sync_r_or_rr(t_stack *stk_a, t_stack *stk_b, t_stack *node)
{
	t_stack	*prev;
	int		rotation;
	int		rev_rotation;

	prev = get_previous(stk_b, node);
	rotation = get_rot_cost(stk_a, node);
	rev_rotation = get_rev_rot_cost(stk_a, node);
	if (get_rot_cost(stk_b, prev) < rotation)
		rotation = get_rot_cost(stk_b, prev);
	if (get_rev_rot_cost(stk_b, prev) < rev_rotation)
		rev_rotation = get_rev_rot_cost(stk_b, prev);
	if (rotation < rev_rotation)
		return (true);
	return (false);
}

void	sync_rotate(t_stack **stk_a, t_stack **stk_b, t_stack *node)
{

	while (*stk_a != node && *stk_b != prev)
	{
		//rotate A
		//rotate B
		//write
	}
	while (stk_a != node)
	{
		// rotate A
		// write
	}
	while (stk_b != prev)
	{
		// rotate B
		// write
	}
}

void	sync_to_top(t_stack **stk_a, t_stack **stk_b, t_stack *node)
{
	t_stack	*prev;

	prev = get_previous(stk_b, node);
	if (sync_r_or_rr(*stk_a, *stk_b, node) == true)
	{
		// perform sync rotation
	}
	else
	{
		// perform sync rev_rotation
	}
}

// Takes care of pushing the cheapest node from stk_a
// into stk_b
void push_to_stk_b(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*cheapest;
	int		sync;
	int		unsync;

	while (stk_cnt_nds(*stk_a) > 3)
	{
		cheapest = find_cheapest(*stk_a, *stk_b);
		sync = get_sync_cst(*stk_a, *stk_b, cheapest);
		unsync = get_unsync_cst(*stk_a, *stk_b, cheapest);
		if (sync < unsync)
		{

		}
		else
		{

		}
	}
}

t_bool	run_push_swap(t_stack **stk_a, t_stack **stk_b)
{
	if (!*stk_a || !*stk_b)
		return (false);
	push_two(stk_a, stk_b);
	push_to_stk_b(stk_a, stk_b);
	return (true);
}

int	main(void)
{
	t_stack	*stk_a;
	t_stack *stk_b;

	stk_a = tst_make_stack(9, 543, 1);
	stk_b = tst_make_stack(1, 53, 1);
	printf("Original stacks\n");
	printf("stk a\n");
	tst_print_stack(stk_a);
	printf("stk b\n");
	tst_print_stack(stk_b);
	run_push_swap(&stk_a, &stk_b);
	printf("Altered stacks\n");
	printf("stk a\n");
	tst_print_stack(stk_a);
	printf("stk b\n");
	tst_print_stack(stk_b);
	return (0);
}
