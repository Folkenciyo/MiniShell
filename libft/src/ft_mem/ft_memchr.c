/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:01:07 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/24 21:01:09 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p_chr;

	p_chr = (unsigned char *)str;
	while (n--)
	{
		if (*p_chr != (unsigned char)c)
			p_chr++;
		else
			return (p_chr);
	}
	return (0);
}
