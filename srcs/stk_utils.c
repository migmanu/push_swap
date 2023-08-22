/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:37:37 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/22 23:10:27 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stk_get_last(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

t_bool	stk_add_end(t_stack **stk, t_stack *new_node)
{
	t_stack	*curr;

	if (stk)
	{
		if (*stk)
		{
			curr = *stk;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new_node;
			return (true);
		}
		else
		{
			*stk = new_node;
			return (true);
		}
	}
	return (false);
}

t_stack	*stk_get_min(t_stack *stk)
{
	t_stack	*min;

	min = stk;
	while (stk != NULL)
	{
		if (stk->nbr < min->nbr)
			min = stk;
		stk = stk->next;
	}
	return (min);
}

int	main (void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*min;
	stk_a = tst_make_stack(5, 100, 1);
	tst_print_stack(stk_a);
	min = stk_get_min(stk_a);
	printf("min: %ld\n", min->nbr);
	return (0);
}
