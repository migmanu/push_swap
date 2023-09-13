/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsync_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:13:41 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/13 19:32:26 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Router function used to chose and execute cheapest path for each
// stack
void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	printf("unsync to top init. nd_a %ld, nd_b %ld\n", nd_a->nbr, nd_b->nbr);
	if (get_rot_cost(*stk_a, nd_a) < get_rev_rot_cost(*stk_a, nd_a))
	{
		printf("rotate a\n");
		while (*stk_a != nd_a)
			rotate(stk_a);
	}
	else
	{
		printf("rev rotate a\n");
		while (*stk_a != nd_a)
			rev_rotate(stk_a);
	}
	if (get_rot_cost(*stk_b, nd_b) < get_rev_rot_cost(*stk_b, nd_b))
	{
		printf("rotate b\n");
		while (*stk_b != nd_b)
			rotate(stk_b);
	}
	else
	{
		printf("rev rotate b\n");
		while (*stk_b != nd_b)
			rev_rotate(stk_b);
	}
}
