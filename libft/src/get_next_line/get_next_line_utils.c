/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:23:42 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/19 01:23:44 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str != NULL)
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = (char *)str;
	while (tmp && *tmp != (char)c)
	{
		if (*tmp == '\0')
			return (NULL);
		tmp++;
	}
	return (tmp);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char)
			* (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
