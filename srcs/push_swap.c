/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:26 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/11 18:57:49 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stk_a;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (check_str(argv[1], 1) == false)
			return(write(1, "Error\n", 6));
	}
	else
	{
		if (check_args(argc, argv) == false)
			return(write(1, "Error\n", 6));
	}
	stk_a = create_stack(argc, argv);
	return (0);
}
