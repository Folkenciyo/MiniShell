/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:57:18 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/27 19:57:19 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static int	words_counter(char const *s, char c)
{
	int	i;
	int	w_counter;
	int	flag;

	i = 0;
	w_counter = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			w_counter++;
			flag = 1;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (w_counter);
}

static int	c_w_cnt(char const *s, char c)
{
	int	j;

	j = 0;
	while (s[j] != '\0' && s[j] != c)
		j++;
	return (j);
}

static char	**allocate_memory(char const *s, char c)
{
	char	**arr;
	int		words;

	words = words_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr || !s)
		return (NULL);
	return (arr);
}

void	free_cpp(char **arr, int words)
{
	while (words-- > 0)
	{
		free(arr[words]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		flag;

	flag = 0;
	words = 0;
	arr = allocate_memory(s, c);
	if (!arr || !s)
		return (free(arr), NULL);
	while (*s != '\0')
	{
		if (*s != c && flag == 0)
		{
			arr[words] = ft_substr(s, 0, c_w_cnt(s, c));
			if (!arr[words])
				return (free_cpp(arr, words), NULL);
			flag = 1;
			words++;
		}
		if (*s == c && flag == 1)
			flag = 0;
		s++;
	}
	arr[words] = NULL;
	return (arr);
}
