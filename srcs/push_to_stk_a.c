/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stk_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:28:20 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/12 21:50:15 by migmanu          ###   ########.fr       */
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
	t_stk	*max_b;
	t_stk	*prev;

	max_b = stk_get_max(*stk_b);
	prev = get_previous_in_a(*stk_a, max_b);
	if (get_rot_cost(stk_a, prev) < get_rev_rot_cost(stk_a, prev))
	{
		rotate();
	}
	else
	{
		rev_rotate();
	}
}


int	main(void)
{
	t_stk	*stk;
	t_stk	*previous;
	t_stk	*node;

	node = malloc(sizeof(t_stk));
	node->next = NULL;
	node->nbr = 1;
	stk = tst_make_stack(5, 76, 1);
	tst_print_stk(stk);
	previous = get_previous_in_a(stk, node);
	printf("\n\n%ld\n", previous->nbr);
	return (0);
}
