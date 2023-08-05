/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:40:27 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/06 00:11:22 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*do_sa(t_stack **stack_a)
{
	t_stack	*buf;
	
	if (stack_a)
	{
		if (*stack_a && (*stack_a)->next)
		{
			buf = (*stack_a)->next;
			(*stack_a)->next = buf->next;
			buf->next = *stack_a;
			stack_a = &buf;
			printf("%d\n\n", (*stack_a)->nbr);
			return (*stack_a);
		}
	}
}

int	main (void)
{
	t_stack	*root;
	root = tst_make_stack(5);
	root = do_sa(&root);
	tst_print_stack(&root);
	return (0);
}
