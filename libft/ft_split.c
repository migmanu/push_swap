/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- jmigoya-@student.42berlin.de      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:22:49 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/17 00:39:47 by migmanu          ###   ########.fr       */
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

char	*copy_word(const char *s, int start, int end)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (end + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[end] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**vec;
	int		end;
	int		start;
	int		word;

	vec = malloc((get_vec_size(s, c) + 1) * sizeof(char *));
	if (!s || !vec)
		return (0);
	vec[get_vec_size(s, c)] = NULL;
	end = 0;
	word = 0;
	while (s[end] != '\0')
	{
		printf("while init\n");
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		vec[word] = copy_word(s, start, end);
		word++;
	}
	return (vec);
}

int main(void)
{
    char *s = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
    char c = ' ';
	printf("number of words:%d\n", get_vec_size(s, c));

    char **res = ft_split(s, c);
	if (!res)
	{
		printf("null return\n");
		return (0);
	}
    if (*res)
    {
		printf("valid return\n");
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
