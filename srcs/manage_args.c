/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:44:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/11 15:51:28 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File for storing input related functions: check valid, convert to int.
#include "push_swap.h"

// Basic function that check all chars are numbers. Toggle determines 
// wether space character is considered ok
t_bool	check_str(char *str, int toggle)
{
	int	k;

	k = 0;
	if (str[k] == '\0')
		return (false);
	while (str[k] != '\0')
	{
		if (toggle == 0)
		{
			if (str[k] < 48 || str[k] > 58)
				return (false);
		}
		else
		{
			if ((str[k] < 48 || str[k] > 58) && str[k] != 32)
				return (false);
		}
		k++;
	}
	return (true);
}

t_bool	check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_str(argv[i], 0) == false)
			return (false);
		i++;
	}
	return (true);
}
/*
int	main(void)
{
	char *args[3];
	args[0] = "not checked";
	args[1] = "125";
	args[2] = "";
	printf("%d\n", check_args(3, args));
	printf("str %d", check_str(""));
	return (0);
}*/
