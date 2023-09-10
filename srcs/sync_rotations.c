/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:52:38 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/10 18:53:34 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Decides wether rotation or rev rotation is cheaper for a sync move.
// Returns true if rotations is cheaper and false if rev_rotation is cheaper
t_bool	sync_r_or_rr(t_stk *stk_a, t_stk *stk_b, t_stk *node)
{
	t_stk	*prev;
	int		rotation;
	int		rev_rotation;

	prev = get_previous(stk_b, node);
	rotation = get_rot_cost(stk_a, node);
	rev_rotation = get_rev_rot_cost(stk_a, node);
	if (get_rot_cost(stk_b, prev) < rotation)
		rotation = get_rot_cost(stk_b, prev);
	if (get_rev_rot_cost(stk_b, prev) < rev_rotation)
		rev_rotation = get_rev_rot_cost(stk_b, prev);
	if (rotation < rev_rotation)
		return (true);
	return (false);
}

void	sync_rotate(t_stk **stk_a, t_stk **stk_b, t_stk *node)
{

	while (*stk_a != node && *stk_b != prev)
	{
		//rotate A
		//rotate B
		//write
	}
	while (stk_a != node)
	{
		// rotate A
		// write
	}
	while (stk_b != prev)
	{
		// rotate B
		// write
	}
}

// Depending on result of sync_r_or_rr calls for sync_rotate
// or sync_rev_rotate
void	sync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *node)
{
	t_stk	*prev;

	prev = get_previous(stk_b, node);
	if (sync_r_or_rr(*stk_a, *stk_b, node) == true)
	{
		// perform sync rotation
	}
	else
	{
		// perform sync rev_rotation
	}
}
