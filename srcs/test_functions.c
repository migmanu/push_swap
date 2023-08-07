/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:06:39 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/07 16:17:01 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates one node and adds it to the end of list
void	tst_add_node_end(t_stack **stack, t_stack *new)
{
	t_stack	*curr;

	if (stack)
	{
		if (*stack)
		{
			curr = *stack;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new;
		}
		else
		{
			*stack = new;
		}
	}
}

// Prints nbr field of each node, starting from root
void	tst_print_stack(t_stack **root)
{
	t_stack	*curr;

	curr = *root;
	while (curr != NULL)
	{
		printf("node %ld\n", curr->nbr);
		curr = curr->next;
	}
}

// Creates a stack of n_nodes size, adding each new node to the end
t_stack	*tst_make_stack(int n_nodes)
{
	t_stack	*root;
	t_stack	*new_node;
	long	i;

	root = NULL;
	if (n_nodes < 0)
		return (NULL);
	i = 0;
	while (i < n_nodes)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->nbr = i;
		new_node->next = NULL;
		tst_add_node_end(&root, new_node);
		i++;
	}
	return (root);
}

/*
int	main(void)
{
	t_stack *root;
	root = tst_make_stack(-2);
	tst_print_stack(&root);
	return (0);
}*/
