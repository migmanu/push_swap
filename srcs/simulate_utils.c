/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:32:28 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/25 16:04:58 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function that takes a node and compares its nbr
// with those of the stack. It returns a link to the
// node within the stack that has the closest lesser
// nbr.
t_stack	*get_previous(t_stack *stk, t_stack *node)
{
	t_stack	*curr;
	t_stack	*previous;

	if (node->nbr > (stk_get_max(stk))->nbr)
		return (stk_get_max(stk));
	if (node->nbr < (stk_get_min(stk))->nbr)
		return (stk_get_max(stk));
	previous = stk_get_min(stk);
	curr = stk;
	while (curr)
	{
		if ((curr->nbr < node->nbr) && (curr->nbr > previous->nbr))
			previous = curr;
		curr = curr->next;
	}
	return (previous);
}

int	main(void)
{
	t_stack	*stk;
	t_stack	*previous;
	t_stack	*node;
	node->next = NULL;
	node->nbr = 3;
	stk = tst_make_stack(5, 76, 1);
	tst_print_stack(stk);
	previous = get_previous(stk, node);
	printf("\n\n%ld\n", previous->nbr);
	return (0);
}
