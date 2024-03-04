/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:19:20 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/24 21:19:22 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_memcmp(const void *buffer1, const void *buffer2, size_t count)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = buffer1;
	p2 = buffer2;
	while (count--)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		else
		{
			p1++;
			p2++;
		}
	}
	return (0);
}
