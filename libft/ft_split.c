/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- jmigoya-@student.42berlin.de      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:22:49 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/11 19:59:45 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_allocate(char **vec, const char *s, char c)
{
	int	i;
	int	k;
	int	str_nbr;

	i = 0;
	str_nbr = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			k = i;
			while (s[k] != c && s[k] != '\0')
				k++;
			vec[str_nbr] = ft_substr(s, i, (k - i));
			str_nbr++;
			i = k;
		}
		i++;
	}
	vec[str_nbr] = NULL;
}

int	ft_count_strs(const char *s, char c)
{
	int	i;
	int	result;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result += 1;
			while (s[i + 1] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**vec;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_strs(s, c);
	vec = malloc(sizeof(char *) * size + 1);
	if (!vec)
		return (NULL);
	ft_allocate(vec, s, c);
	return (vec);
}

int main(int argc, char *argv[])
{
    char *s = argv[1];
    char c = ' ';
	//printf("strs: %d\n", ft_count_strs(s, c));
	printf("str: %s\n", s);

    char **res = ft_split(s, c);
    if (res)
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
	free(res);
    return 0;
}
