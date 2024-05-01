/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:48:58 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/27 10:49:07 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*p;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
