/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:23:16 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/06 19:32:29 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function used to free any given linked list stk
t_bool	free_stk(t_stack *stk)
{
	t_stack	*cur;
	t_stack	*tmp;

	if (!stk)
		return (false);
	cur = stk;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	return (true);
}

int	main(void)
{
	t_stack	*stk;
	stk = tst_make_stack(40, 122, 1);
	free_stk(stk);
	return (0);
}
