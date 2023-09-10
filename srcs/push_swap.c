/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:26 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/10 18:45:54 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stk	*stk_a;
	char	**vec;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		vec = ft_split(argv[1], ' ');
		if (!vec)
			return (0);
		argc = vec_size(argv[1], ' ');
	}
	else
	{
		vec = argv + 1;
		argc -= 1;
	}
	if (check_args(argc, vec) == false)
		return (write(1, "Error\n", 6));
	stk_a = create_stack(argc, vec);
	tst_print_stk(stk_a);
	check_numbers(stk_a);
	// free whole vector
	//stk_a = create_stack(argc, argv);
	return (0);
}
