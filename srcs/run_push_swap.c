/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:26:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/10 20:43:52 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push just two nodes from stk_a to stk_b, as long as
// theres at least 3 nodes remaining at stk_a
void	push_two(t_stk **stk_a, t_stk **stk_b)
{
	if (stk_cnt_nds(*stk_a) > 3)
		push(stk_a, stk_b);
	if (stk_cnt_nds(*stk_a) > 3)
		push(stk_a, stk_b);
}

// Takes care of pushing the cheapest node from stk_a
// into stk_b
void push_to_stk_b(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*cheapest;
	int		sync;
	int		unsync;

	while (stk_cnt_nds(*stk_a) > 3)
	{
		cheapest = find_cheapest(*stk_a, *stk_b);
		sync = get_sync_cst(*stk_a, *stk_b, cheapest);
		unsync = get_unsync_cst(*stk_a, *stk_b, cheapest);
		if (sync < unsync)
		{

		}
		else
		{

		}
	}
}

t_bool	run_push_swap(t_stk **stk_a, t_stk **stk_b)
{
	if (!*stk_a || !*stk_b)
		return (false);
	push_two(stk_a, stk_b);
	push_to_stk_b(stk_a, stk_b);
	return (true);
}

int	main(void)
{
	t_stk	*stk_a;
	t_stk *stk_b;

	stk_a = tst_make_stack(9, 543, 1);
	stk_b = tst_make_stack(1, 53, 1);
	printf("Original stacks\n");
	printf("stk a\n");
	tst_print_stk(stk_a);
	printf("stk b\n");
	tst_print_stk(stk_b);
	run_push_swap(&stk_a, &stk_b);
	printf("Altered stacks\n");
	printf("stk a\n");
	tst_print_stk(stk_a);
	printf("stk b\n");
	tst_print_stk(stk_b);
	return (0);
}
