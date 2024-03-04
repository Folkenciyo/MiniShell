/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:40:05 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/27 16:40:07 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static char	char_compare(char s1_char, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1_char == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && char_compare(s1[start], set))
		start++;
	while (end > start && char_compare(s1[end - 1], set))
		end--;
	new_str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (new_str == NULL)
		return (NULL);
	while (start < end)
	{
		new_str[i] = s1[start];
		start++;
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
