/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsync_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:13:41 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/11 01:26:01 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Router function used to chose and execute cheapest path for each
// stack
void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *node)
{
	t_stk	*prev;

	prev = get_previous(stk_b, node);
	if (get_rot_cost(stk_a, node) < get_rev_rot_cost(stk_a, node))
	{
		// rotate
	}
	else
	{
		// rev_rotate
	}
	if (get_rot_cost(stk_b, prev) < get_rev_rot_cost(stk_b, prev))
	{
		// rotate
	}
	else
	{
		// rev_rotate
	}
}
	
