/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:37:37 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/18 16:33:00 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	stklast(t_stack *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk->next != NULL)
		stk = lst->next;
	return (stk);
}

t_stack	stk_add_last(t_stack *stk, t_stack node)
{

}