/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:52:38 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/13 18:52:01 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Executes sync_rotate as needed to position nd_a and nd_b on top of
// each of their stacks
void	do_sync_rotate(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	while (*stk_a != nd_a && *stk_b != nd_b)
	{
		sync_rotate(stk_a, stk_b);
		write(1, "rr\n", 3);
	}
	while (*stk_a != nd_a)
	{
		rotate(stk_a);
		write(1, "ra\n", 3);
	}
	while (*stk_b != nd_b)
	{
		rotate(stk_b);
		write(1, "rb\n", 3);
	}
}

// Executes sync_rev_rotate as needed to position nd_a and nd_b on top of
// each of their stacks
void	do_sync_r_rot(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	while (*stk_a != nd_a && *stk_b != nd_b)
	{
		sync_rev_rotate(stk_a, stk_b);
		write(1, "rrr\n", 4);
	}
	while (*stk_a != nd_a)
	{
		rev_rotate(stk_a);
		write(1, "rra\n", 4);
	}
	while (*stk_b != nd_b)
	{
		rev_rotate(stk_b);
		write(1, "rrb\n", 4);
	}
}

// Decides wether rotation or rev rotation is cheaper for a sync move.
// Returns true if rotations is cheaper and false if rev_rotation is cheaper
t_bool	sync_r_or_rr(t_stk *stk_a, t_stk *stk_b, t_stk *nd_a, t_stk *nd_b)
{
	int		rotation;
	int		rev_rotation;

	rotation = get_rot_cost(stk_a, nd_a);
	rev_rotation = get_rev_rot_cost(stk_a, nd_a);
	if (get_rot_cost(stk_b, nd_b) > rotation)
		rotation = get_rot_cost(stk_b, nd_b);
	if (get_rev_rot_cost(stk_b, nd_b) > rev_rotation)
		rev_rotation = get_rev_rot_cost(stk_b, nd_b);
	if (rotation < rev_rotation)
		return (true);
	return (false);
}

// Depending on result of sync_r_or_rr calls for sync_rotate
// or sync_rev_rotate
void	sync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	if (sync_r_or_rr(*stk_a, *stk_b, nd_a, nd_b) == true)
	{
		printf("rotate\n");
		do_sync_rotate(stk_a, stk_b, nd_a, nd_b);
	}
	else
	{
		printf("rev_rotate\n");
		do_sync_r_rot(stk_a, stk_b, nd_a, nd_b);
	}
}
/*
int	main(void)
{
	t_stk	*cheapest;
	t_stk	*nd_b;
	t_stk	*stk_a;
	t_stk	*stk_b;
	stk_a = tst_make_stack(5, 23, 1);
	stk_b = tst_make_stack(1, 54, 1);
	printf("stk A\n");
	tst_print_stk(stk_a);
	printf("stk B\n");
	tst_print_stk(stk_b);
	while (stk_cnt_nds(stk_a) > 3)
	{
		cheapest = find_cheapest(stk_a, stk_b);
		nd_b = get_nd_bious(stk_b, cheapest);
		sync_to_top(&stk_a, &stk_b, cheapest);
		push(&stk_a, &stk_b);
		write(1, "pb\n", 3);
	}
	printf("\nAFTER\n");
	printf("stk A\n");
	tst_print_stk(stk_a);
	printf("stk B\n");
	tst_print_stk(stk_b);
	return (0);
}*/
