/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:26 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/18 15:44:20 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stk_a;
	char	**vec;

	printf("at start: %s\n", argv[1]);
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		printf("only one arg passed\n");
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
	printf("vec: %s\n", vec[0]);
	printf("vec: %s\n", vec[1]);
	stk_a = create_stack(argc, vec);
	// free whole vector
	/*
	if (check_args(argc, vec) == false)
		return(write(1, "Error\n", 6));*/
	//stk_a = create_stack(argc, argv);
	return (0);
}
