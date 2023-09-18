/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:23:16 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/15 19:53:15 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function used to free any given linked list stk
t_bool	free_stk(t_stk *stk)
{
	t_stk	*cur;
	t_stk	*tmp;

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

// Function used to free created vector in case of arg error.
void	free_vector(int argc, char *argv[])
{
	int	i;

	if (argv == NULL)
		return ;
	i = 0;
	while (i < argc)
	{
		argv[i] = NULL;
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	argv = NULL;
	free(argv);
	argv = NULL;
}

/*
int	main(void)
{
	t_stk	*stk;
	stk = tst_make_stack(40, 122, 1);
	free_stk(stk);
	return (0);
}*/
