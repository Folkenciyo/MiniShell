/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:19:47 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/27 14:19:50 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		s1_len;
	int		s2_len;
	int		full_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	full_len = s1_len + s2_len + 1;
	new_str = malloc(full_len);
	i = 0;
	if (!new_str)
		return (NULL);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < full_len - 1)
	{
		new_str[i] = *s2++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
