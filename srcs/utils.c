/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:32:03 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/05 19:32:12 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In case user inputs a string of numbers. vec_size counts the amount
// of numbers present. It does so by using char c as a separator (in 
// this case it should only be a space char).
int	vec_size(const char *s, char c)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (result);
}
