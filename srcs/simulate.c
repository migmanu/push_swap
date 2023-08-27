/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:15:50 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/27 17:21:07 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cost(t_stack *stk_a, t_stack *stk_b, t_stack *node, t_stack *prev)
{
	int	rotation;
	int	rev_rotation;

	rotation = rot_to_top(rotate, stk_a, node);
	printf("rotation:%d\n", rotation);
	if (rot_to_top(rotate, stk_b, prev) > rotation)
	{
		printf("bigger than\n");
		tst_print_stack(stk_b);
		//rotation = rot_to_top(rotate, stk_b, prev);
	}
	printf("rev rotation\n");
	rev_rotation = rot_to_top(rev_rotate, stk_a, node);
	if (rot_to_top(rev_rotate, stk_b, prev) > rev_rotation)
		rev_rotation = rot_to_top(rev_rotate, stk_b, prev);
	printf("\nrotation:%d, rev_rotation:%d\n", rotation, rev_rotation);
	if (rotation < rev_rotation)
		return (rotation);
	return (rev_rotation);
}

t_stack	*find_cheapest(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*curr;
	t_stack	*prev;
	t_stack	*cheapest;
	int		cost;

	cost = INT_MAX;
	curr = stk_a;
	while (curr)
	{
		printf("while init\n");
		prev = get_previous(stk_b, curr);
		printf("prev:%ld\n", prev->nbr);
		if (find_cost(stk_a, stk_b, curr, prev) < cost)
		{
			cost = find_cost(stk_a, stk_b, curr, prev);
			cheapest = curr;
		}
		curr = curr->next;
	}
	return (cheapest);
}

int	main(void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*cheapest;

	stk_a = tst_make_stack(4, 67, 1);
	stk_b = tst_make_stack(4, 97, 1);
	printf("stk_a:\n");
	tst_print_stack(stk_a);
	printf("\nstk_b:\n");
	tst_print_stack(stk_b);
	cheapest = find_cheapest(stk_a, stk_b);
	printf("\n cheapest nbr:%ld", cheapest->nbr);
	return (0);
}
