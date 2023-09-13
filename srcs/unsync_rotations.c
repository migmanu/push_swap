/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsync_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:13:41 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/13 19:47:09 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function needed because of lines limits. If toggle 1 it prints ra,
// else, rb
void	write_n_rotate(t_stk **stk, t_stk *node, int	toggle)
{
	while(*stk != node)
	{
		if (toggle == 1)
			write(1, "ra\n", 3);
		if (toggle == 0)
			write(1, "rb\n", 3);
		rotate(stk);
	}
}

// Function needed because of lines limits. If toggle 1 it prints rra,
// else, rrb
void	write_n_rev_rotate(t_stk **stk, t_stk *node, int	toggle)
{
	while(*stk != node)
	{
		if (toggle == 1)
			write(1, "rra\n", 4);
		if (toggle == 0)
			write(1, "rrb\n", 4);
		rev_rotate(stk);
	}
}

// Router function used to chose and execute cheapest path for each
// stack
void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	printf("unsync to top init. nd_a %ld, nd_b %ld\n", nd_a->nbr, nd_b->nbr);
	if (get_rot_cost(*stk_a, nd_a) < get_rev_rot_cost(*stk_a, nd_a))
	{
		write_n_rotate(stk_a, nd_a, 1);
	}
	else
	{
		write_n_rev_rotate(stk_a, nd_a, 1);
	}
	if (get_rot_cost(*stk_b, nd_b) < get_rev_rot_cost(*stk_b, nd_b))
	{
		write_n_rotate(stk_b, nd_b, 0);
	}
	else
	{
		write_n_rev_rotate(stk_b, nd_b, 0);
	}
}
