/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:44:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/08/17 19:41:45 by migmanu          ###   ########.fr       */
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

t_bool	check_repeated(char *argv[])
{
	int	i;
	int	curr;
	int	len;
	printf("repeated init\n");

	i = 0;
	while (argv[i] != NULL)
	{
		curr =  i++;
		len = ft_strlen(argv[curr]);
		printf("gonna check %s\n", argv[curr]);
		while (argv[i + 1] != NULL)
		{
			printf("check %s against %s\n", argv[curr], argv[i]);
			if (ft_strncmp(argv[curr], argv[i], len + 1) == 0)
			{
				printf("repeated args: %s and %s\n", argv[curr], argv[i]);
				return (false);
			}
			i++;
			printf("i %d\n", i);
		}
		i = curr;
		printf("end i: %d\n");
	}
	printf("no repeated args\n");
	return (true);
}

t_bool	check_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		printf("checking: %s\n", argv[i]);
		if (check_str(argv[i], 0) == false || check_repeated(argv) == false)
			return (false);
		i++;
	}
	return (true);
}

int	main(void)
{
	char *args[3];
	args[0] = "125";
	args[1] = "1125";
	args[2] = "1";
	char	*str1 = "123";
	char	*str2 = "123";
	int	len = ft_strlen(str1);
	//printf("%d\n", ft_strncmp(str1, str2, len + 1));
	printf("%d\n", check_args(3, args));
	//printf("str %d", check_str(""));
	return (0);
}
