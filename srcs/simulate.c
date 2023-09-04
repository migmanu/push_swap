/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:15:50 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/03 20:23:01 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rot_cost(t_stack *stk, t_stack *node)
{
	int	result;

	result = 0;
	while (stk->nbr != node->nbr)
	{
		result++;
		stk = stk->next;
	}
	return (result);
}

int	get_rev_rot_cost(t_stack *stk, t_stack *node)
{
	int	result;

	result = 0;
	if (stk->nbr == node->nbr)
		return (result);
	while (stk->nbr != node->nbr)
		stk = stk->next;
	while (stk)
	{
		result++;
		stk = stk->next;
	}
	return (result);
}

int	get_sync_cst(t_stack *stk_a, t_stack *stk_b, t_stack *node)
{
	int		rot_cost;
	int		rev_rot_cost;
	t_stack	*prev;

	prev = get_previous(stk_b, node);
	if (get_rot_cost(stk_a, node) > get_rot_cost(stk_b, prev))
		rot_cost = get_rot_cost(stk_a, node);
	else
		rot_cost = get_rot_cost(stk_b, prev);
	if (get_rev_rot_cost(stk_a, node) > get_rev_rot_cost(stk_b, prev))
		rev_rot_cost = get_rev_rot_cost(stk_a, node);
	else
		rev_rot_cost = get_rev_rot_cost(stk_b, prev);
	if (rot_cost < rev_rot_cost)
	{
		return (rot_cost);
	}
	return (rev_rot_cost);
}

int	get_unsync_cst(t_stack *stk_a, t_stack *stk_b, t_stack *node)
{
	int		node_cost;
	int		prev_cost;
	t_stack	*prev;

	prev = get_previous(stk_b, node);
	if (get_rot_cost(stk_a, node) < get_rev_rot_cost(stk_a, node))
		node_cost = get_rot_cost(stk_a, node);
	else
		node_cost = get_rev_rot_cost(stk_a, node);
	if (get_rot_cost(stk_b, prev) < get_rev_rot_cost(stk_b, prev))
		prev_cost = get_rot_cost(stk_b, prev);
	else
		prev_cost = get_rev_rot_cost(stk_b, prev);
	return (node_cost + prev_cost);
}

t_stack	*find_cheapest(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*cheapest;
	t_stack	*cur;
	int		cost;

	cost = INT_MAX;
	cur = stk_a;
	while (cur)
	{
		if (get_sync_cst(stk_a, stk_b, cur) < cost)
		{
			cost = get_sync_cst(stk_a, stk_b, cur);
			cheapest = cur;
		}
		if (get_unsync_cst(stk_a, stk_b, cur) < cost)
		{
			cost = get_unsync_cst(stk_a, stk_b, cur);
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
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*cheapest;
	t_stack	*min_a;
	t_stack	*min_b;
	int		arr_a[] = {6, 3, 9, 4, 8};
	int		arr_b[] = {1, 7, 5, 2};

	stk_a = tst_make_arr_stk(arr_a, 5);
	stk_b = tst_make_arr_stk(arr_b, 4);
	min_a = stk_get_min(stk_a);
	min_b = stk_get_min(stk_b);
	printf("stk_a:\n");
	tst_print_stack(stk_a);
	printf("\nstk_b:\n");
	tst_print_stack(stk_b);
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