/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:19:16 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/07 22:43:33 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push first node from stack src to first position in
// stack dest
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*buf;

	if (!*src || !*dest)
		return ;
	buf = *src;
	*src = (*src)->next;
	buf->next = *dest;
	*dest = buf;
}

/*
int	main (void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	stk_a = tst_make_stack(4, 43, 1);
	stk_b = tst_make_stack(4, 54, 1);
	printf("\nstack A\n");
	tst_print_stack(stk_a);
	printf("\nstack B\n");
	tst_print_stack(stk_b);
	printf("\npush to b\n");
	push(&stk_a, &stk_b);
	printf("\nstack A\n");
	tst_print_stack(stk_a);
	printf("\nstack B\n");
	tst_print_stack(stk_b);
	printf("\npush to a\n");
	push(&stk_b, &stk_a);
	printf("\nstack A\n");
	tst_print_stack(stk_a);
	printf("\nstack B\n");
	tst_print_stack(stk_b);
	return (0);
}*/
