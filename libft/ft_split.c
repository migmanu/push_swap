/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- jmigoya-@student.42berlin.de      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:22:49 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/14 17:24:24 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_vec_size(const char *s, char c)
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

char	**ft_split(const char *s, char c)
{
	char **vec;
	int	end;
	int	start;

	vec = malloc((get_vec_size(s, c) + 1) * sizeof(char *));
	if (!s || !vec)
		return (0);
	vec[get_vec_size(s, c)] = NULL;
	i = 0;
	while (s[end] != '\0')
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
	}
	return (vec);
}


int main(void)
{
    char *s = "";
    char c = ' ';
	printf("%d", get_vec_size(s, c));
/*
    char **res = ft_split(s, c);
	if (!res)
		return (0);
    if (*res)
    {
		int i = 0;
        while (res[i])
        {
			printf("%s\n", res[i]);
			free(res[i]);
			res[i] = NULL;
            i++;
        }
    }
	free(res);*/
    return 0;
}
