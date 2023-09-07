/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:33:07 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/07 17:34:13 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate(t_stack *stk)
{
	t_stack	*last;
	t_stack	*buf;

	if (!stk || !stk->next)
		return (NULL);
	buf = stk;
	stk = stk->next;
	last = stk_get_last(buf);
	buf->next = NULL;
	last->next = buf;
	return (stk);
}

t_stack	*rev_rotate(t_stack *stk)
{
	t_stack	*last;
	t_stack	*buf;

	if (!stk || !stk->next)
		return (NULL);
	last = stk_get_last(stk);
	buf = stk;
	while (buf->next != last)
		buf = buf->next;
	buf->next = NULL;
	last->next = stk;
	stk = last;
	return (stk);
}
