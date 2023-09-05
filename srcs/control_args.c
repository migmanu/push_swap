/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:44:30 by migmanu           #+#    #+#             */
/*   Updated: 2023/09/05 19:06:36 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Applies the check_str to each node
t_bool	check_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (check_str(argv[i], 0) == false)
			return (false);
		i++;
	}
	return (true);
}

// Goes through the linked list and checks for invalid numbers.
// Kills program if invalid
void	check_numbers(t_stack *stk)
{
	t_stack	*curr;
	t_stack	*compare;
	long	curr_nbr;

	curr = stk;
	while (curr->next != NULL)
	{
		curr_nbr = curr->nbr;
		if (curr_nbr < INT_MIN || curr_nbr > INT_MAX)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		compare = curr->next;
		while (compare != NULL)
		{
			if (curr->nbr == compare->nbr)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			compare = compare->next;
		}
		curr = curr->next;
	}
}
/*
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

	t_stack *stk = tst_make_stack(5);
	stk->nbr = INT_MAX;
	tst_print_stack(stk);
	check_repeated(stk);
	return (0);
}*/
