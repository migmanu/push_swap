/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvs_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:16:28 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/24 00:18:02 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stk)
{
	t_stack	*last;
	t_stack	*buf;

	if (!*stk || !(*stk)->next)
		return (-1);
	buf = *stk;
	*stk = (*stk)->next;
	last = stk_get_last(buf);
	buf->next = NULL;
	last->next = buf;
	return (1);
}

void	rot_to_top(t_stack *stk, t_stack *node)
{
	t_stack	*curr;
	int	result;

	printf("rot init first: %ld node: %ld\n", stk->nbr, node->nbr);
	curr = stk;
	result = 0;
	while (curr && curr->nbr != node->nbr)
	{
		curr = curr->next;
		rotate(&stk);
		result += 1;
	}
	printf("result: %d\n", result);
	tst_print_stack(stk);
}

int	main(void)
{
	t_stack	*stk;

	stk = tst_make_stack(5, 99, 1);
	tst_print_stack(stk);
	t_stack *min = stk_get_min(stk);
	rot_to_top(stk, min);
	return (0);
}
