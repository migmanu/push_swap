/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:26:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/07 22:54:55 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	run_push_swap(t_stack **stk_a, t_stack **stk_b)
{
	if (!*stk_a || !*stk_b)
		return (false);
	while (stk_cnt_nds(*stk_a) > 3)
	{
		printf("count: %d\n", stk_cnt_nds(*stk_a));
		push(stk_a, stk_b);
	}
	return (true);
}

int	main(void)
{
	t_stack	*stk_a;
	t_stack *stk_b;

	stk_a = tst_make_stack(5, 543, 1);
	stk_b = tst_make_stack(5, 53, 1);
	printf("Original stacks");
	tst_print_stack(stk_a);
	tst_print_stack(stk_b);
	run_push_swap(&stk_a, &stk_b);
	printf("Altered stacks");
	tst_print_stack(stk_a);
	tst_print_stack(stk_b);
	return (0);
}
