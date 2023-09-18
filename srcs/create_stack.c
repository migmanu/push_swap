/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:59:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/15 19:50:50 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates a stack (linked list) from the inputed
// array of array of numbers
t_stk	*create_stack(int argc, char **vec)
{
	t_stk	*stk_a;
	t_stk	*new_node;
	int		i;

	stk_a = NULL;
	i = 0;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_stk));
		if (!new_node)
			return (NULL);
		new_node->nbr = ft_atol(vec[i]);
		new_node->next = NULL;
		i++;
		if (stk_add_end(&stk_a, new_node) == false)
			return (NULL);
	}
	return (stk_a);
}
/*
int	main(void)
{
	t_stk *root;
	char *args[3];
	args[0] = "-125";
	args[1] = "1125";
	args[2] = "-2147483658";
	root = create_stack(3, args);
	tst_print_stk(&root);
	return (0);
}*/
