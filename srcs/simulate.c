/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:15:50 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/13 16:27:50 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get the amount of movements needed in order to rotate any given node
// to the top of any given stack.
int	get_rot_cost(t_stk *stk, t_stk *node)
{
	int	result;

	result = 0;
	if (stk->nbr == node->nbr)
	{
		return (result);
	}
	while (stk->nbr != node->nbr)
	{
		result++;
		stk = stk->next;
	}
	return (result);
}

// Get the amount of movements needed in order to reverse rotate any given
// node to the top of any given stack.
int	get_rev_rot_cost(t_stk *stk, t_stk *node)
{
	int	result;

	result = 0;
	if (stk->nbr == node->nbr)
	{
		return (result);
	}
	while (stk->nbr != node->nbr)
		stk = stk->next;
	while (stk)
	{
		result++;
		stk = stk->next;
	}
	return (result);
}

// Get the amount of movements needed to get a node from stk_a and its
// corresponding previous node from stk_b both into top position,
// using either rr or rrr.
int	get_sync_cst(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev)
{
	int		rot_cost;
	int		rev_rot_cost;

	printf("sync_cst init, node %ld prev: %ld\n", node->nbr, prev->nbr);
	printf("stk a\n");
	tst_print_stk(stk_a);
	printf("stk b\n");
	tst_print_stk(stk_b);
	if (get_rot_cost(stk_a, node) > get_rot_cost(stk_b, prev))
	{
		rot_cost = get_rot_cost(stk_a, node);
	}
	else
	{
		rot_cost = get_rot_cost(stk_b, prev);
	}
	if (get_rev_rot_cost(stk_a, node) > get_rev_rot_cost(stk_b, prev))
	{
		rev_rot_cost = get_rev_rot_cost(stk_a, node);
	}
	else
	{
		rev_rot_cost = get_rev_rot_cost(stk_b, prev);
	}
	if (rot_cost < rev_rot_cost)
	{
		printf("sync cost %d\n", rot_cost);
		return (rot_cost);
	}
	printf("sync cost %d\n", rev_rot_cost);
	return (rev_rot_cost);
}

// Get the amount of movements needed to get a node from stk_a and its
// corresponding previous node from stk_b both into top position,
// using either ra and rra for stk_a and either rb and rrb for stk_b
int	get_unsync_cst(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev)
{
	int		node_cost;
	int		prev_cost;

	printf("get_unsync_cst init, node %ld prev: %ld\n", node->nbr, prev->nbr);
	printf("stk a\n");
	tst_print_stk(stk_a);
	printf("stk b\n");
	tst_print_stk(stk_b);
	if (get_rot_cost(stk_a, node) < get_rev_rot_cost(stk_a, node))
	{
		printf("stk_a\nrotation smaller:%ld\n",get_rot_cost(stk_a, node));
		node_cost = get_rot_cost(stk_a, node);
	}
	else
	{
		printf("stk_a\nrev_rotation smaller:%ld\n",get_rev_rot_cost(stk_a, node));
		node_cost = get_rev_rot_cost(stk_a, node);
	}
	if (get_rot_cost(stk_b, prev) < get_rev_rot_cost(stk_b, prev))
	{
		printf("stk_b\nrotation smaller:%ld\n",get_rot_cost(stk_b, prev));
		prev_cost = get_rot_cost(stk_b, prev);
	}
	else
	{
		printf("stk_b\nrev_rotation smaller:%ld\n",get_rev_rot_cost(stk_b, prev));
		prev_cost = get_rev_rot_cost(stk_b, prev);
	}
	printf("unsync cost %d\n", node_cost + prev_cost);
	return (node_cost + prev_cost);
}

// Find the node from stk_a that would require the least amount of movements
// in order to be pushed into its right position in stk_b
t_stk	*find_cheapest(t_stk *stk_a, t_stk *stk_b)
{
	t_stk	*cheapest;
	t_stk	*cur;
	int		cost;
	t_stk	*prev;

	cost = INT_MAX;
	cur = stk_a;
	while (cur)
	{
		prev = get_previous(stk_b, cur);
		if (get_sync_cst(stk_a, stk_b, cur, prev) < cost)
		{
			cost = get_sync_cst(stk_a, stk_b, cur, prev);
			cheapest = cur;
		}
		if (get_unsync_cst(stk_a, stk_b, cur, prev) < cost)
		{
			cost = get_unsync_cst(stk_a, stk_b, cur, prev);
			cheapest = cur;
		}
		cur = cur->next;
	}
	printf("cheapest node is %ld\n", cheapest->nbr);
	return (cheapest);
}
/*
int	main(void)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	t_stk	*cheapest;
	t_stk	*min_a;
	t_stk	*min_b;
	int		arr_a[] = {6, 3, 9, 4, 8};
	int		arr_b[] = {1, 7, 5, 2};

	stk_a = tst_make_arr_stk(arr_a, 5);
	stk_b = tst_make_arr_stk(arr_b, 4);
	min_a = stk_get_min(stk_a);
	min_b = stk_get_min(stk_b);
	printf("stk_a:\n");
	tst_print_stk(stk_a);
	printf("\nstk_b:\n");
	tst_print_stk(stk_b);
	find_cheapest(stk_a, stk_b);
	// test rot and rev rot
	//printf("\nstk_a:\n");
	//printf("rot min %d: %d\n", min_a->nbr, get_rot_cost(stk_a, min_a));
	//printf("rev rot min%d: %d\n", min_a->nbr, get_rev_rot_cost(stk_a, min_a));
	//printf("\nstk_b:\n");
	//printf("rot min %d: %d\n", min_b->nbr, get_rot_cost(stk_b, min_b));
	//printf("rev rot min %d: %d\n", min_b->nbr, get_rev_rot_cost(stk_b, min_b));
	//cheapest = find_cheapest(stk_a, stk_b);
	//printf("\n cheapest nbr:%ld", cheapest->nbr);
	return (0);
}*/
