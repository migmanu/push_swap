/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:06:39 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/23 18:28:41 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

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
void	tst_print_stack(t_stack *root)
{
	t_stack	*curr;

	curr = root;
	while (curr != NULL)
	{
		printf("nbr: %ld\n", curr->nbr);
		curr = curr->next;
	}
}

t_bool	nbr_in_stk(long nbr, t_stack *stk)
{
	while (stk != NULL)
	{
		if (stk->nbr == nbr)
		{
			return (true);
		}
		stk = stk->next;
	}
	return (false);
}

// creates a stack from an array of numbers, up to n nodes. n must not be larger
// the amount of members of the provided array
t_stack	*tst_make_arr_stk(int *arr, int n)
{
	t_stack	*root;
	t_stack	*new_node;
	int 	i;

	root = NULL;
	i = 0;
	while (i < n)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nbr = arr[i];
		new_node->next = NULL;
		tst_add_node_end(&root, new_node);
		i++;
	}
	return (root);
}

// Creates a random stack of n_nodes size, adding each new node to the end
t_stack	*tst_make_stack(int n_nodes, int max, int random)
{
	t_stack	*root;
	t_stack	*new_node;
	long	i;

	root = NULL;
	if (n_nodes < 0 || n_nodes > max)
	{
		write(1, "args err\n", 10);
		exit(0);
	}
	i = 0;
	while (i < n_nodes)
	{
		new_node = malloc(sizeof(t_stack));
		if (random == 0)
			new_node->nbr = i;
		else
			new_node->nbr = (rand() % max) + 1;
			while (nbr_in_stk(new_node->nbr, root) == true)
				new_node->nbr = (rand() % max) + 1;
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
	int		arr[] = {12, 4, 6, 76, 3};
	root = tst_make_arr_stk(arr, 5);
	tst_print_stack(root);
	return (0);
}*/
