/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:59:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/18 16:02:38 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int argc, char **vec)
{
	t_stack	*stk_a;
	int		i;
	int		nbr;

	stk_a = malloc(sizeof(t_stack *));
	if (!stk_a || !vec)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		nbr = ft_atoi(vec[i++]);
		printf("nbr:%d\n", nbr);
	}
	return (stk_a);
}

int	main(void)
{
	char *args[3];
	args[0] = "125";
	args[1] = "1125";
	args[2] = "-2147483658";
	create_stack(3, args);
	return (0);
}
