/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsync_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:13:41 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/12 14:30:31 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Router function used to chose and execute cheapest path for each
// stack
void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *node)
{
	t_stk	*prev;

	prev = get_previous(*stk_b, node);
	printf("stk a\n");
	tst_print_stk(*stk_a);
	printf("stk b\n");
	tst_print_stk(*stk_b);
	if (get_rot_cost(*stk_a, node) < get_rev_rot_cost(*stk_a, node))
	{
		printf("rotate a\n");
		while (*stk_a != node)
			rotate(stk_a);
	}
	else
	{
		printf("rev rotate a\n");
		while (*stk_a != node)
			rev_rotate(stk_a);
	}
	if (get_rot_cost(*stk_b, prev) < get_rev_rot_cost(*stk_b, prev))
	{
		printf("rotate b\n");
		while (*stk_b != prev)
			rotate(stk_b);
	}
	else
	{
		printf("rev rotate b\n");
		while (*stk_b != prev)
			rev_rotate(stk_b);
	}
}
