/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:37:37 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/05 19:29:19 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get pointer to last node of any given stack
t_stack	*stk_get_last(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

// Add note at end of any given stack
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

// Get pointer to the node with the smalles nbr in any given stack
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

// Get pointer to the node with the largest nbr in any given stack
t_stack	*stk_get_max(t_stack *stk)
{
	t_stack	*max;

	max = stk;
	while (stk != NULL)
	{
		if (stk->nbr > max->nbr)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

// Simple function that counts nodes in stack
int	stk_cnt_nds(t_stack *stk)
{
	t_stack	*cur;
	int		result;

	while (cur)
	{
		result++;
		cur = cur->next;
	}
	return (result);
}
/*
int	main (void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*min;
	t_stack	*max;

	srand( time(NULL) );
	stk_a = tst_make_stack(5, 100, 1);
	tst_print_stack(stk_a);
	min = stk_get_min(stk_a);
	max = stk_get_max(stk_a);
	printf("\nmin: %ld\n", min->nbr);
	printf("max: %ld\n", max->nbr);
	return (0);
}*/
