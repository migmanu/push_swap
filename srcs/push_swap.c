/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:32:26 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/11 14:48:21 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		printf("Two args\n");
		if (check_args(argc, argv))
			printf("string OK");
		else
			printf("Error\n");
	}
	else
	{
		printf("Several args\n");
		if (check_args(argc, argv))
			printf("args OK");
		else
			printf("Error\n");
	}
	//printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
