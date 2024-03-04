/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:46:49 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/19 15:46:51 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = str;
	while (n)
	{
		*(ptr++) = (unsigned char)c;
		n--;
	}
	return (str);
}
