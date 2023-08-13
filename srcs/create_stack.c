/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:59:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/11 19:17:01 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_stack(int argc, char **argv)
{
	t_stack	stk_a;
	char	**vec;
	int		i;

	if (argc == 1)
		vec = ft_split(argv[1], 32);
	else
		vec = argv;

}

int	main(void)
{
	return (0);
}
