/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:19:47 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/20 17:19:50 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_char;
	const char	*src_char;

	i = 0;
	src_char = (char *)src;
	dest_char = (char *)dest;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest > src)
	{
		while (n--)
		{
			dest_char[n] = src_char[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest_char[i] = src_char[i];
			i++;
		}
	}
	return (dest);
}
