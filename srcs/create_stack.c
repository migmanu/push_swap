/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:59:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/20 22:25:36 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int argc, char **vec)
{
	t_stack	*stk_a;
	t_stack	*new_node;
	int		i;

	stk_a = NULL;
	i = 0;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_stack *));
		if (!new_node)
			return (NULL);
		new_node->nbr = ft_atol(vec[i++]);
		new_node->next = NULL;
		if (stk_add_end(&stk_a, new_node) == false)
			return (NULL);
	}
	return (stk_a);
}

int	main(void)
{
	t_stack *root;
	char *args[3];
	args[0] = "-125";
	args[1] = "1125";
	args[2] = "-2147483658";
	root = create_stack(3, args);
	tst_print_stack(&root);
	return (0);
}
