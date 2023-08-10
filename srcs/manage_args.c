/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:44:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/10 21:17:25 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File for storing input related functions: check valid, convert to int.
#include "push_swap.h"

// Basic function that check all char are numbers. Return -1 on error. Empty
// string is treated as error.
int	check_str(char *str)
{
	int	k;

	k = 0;
	if (str[k] == '\0')
		return (-1);
	while (str[k] != '\0')
	{
		if (str[k] < 48 || str[k] > 58)
			return (-1);
		k++;
	}
	return (1);
}

int	check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_str(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	main(void)
{
	char *args[3];
	args[0] = "not checked";
	args[1] = "125";
	args[2] = "";
	printf("%d\n", check_args(3, args));
	printf("str %d", check_str("0"));
	return (0);
}
