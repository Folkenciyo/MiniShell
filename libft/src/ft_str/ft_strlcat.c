/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:51:42 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/22 23:51:45 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_counter;
	size_t	dst_counter;
	size_t	freespace;

	dst_len = (size_t)ft_strlen(dst);
	src_len = (size_t)ft_strlen(src);
	src_counter = 0;
	dst_counter = 0;
	freespace = dstsize - dst_len - 1;
	while (dst[dst_counter] != '\0')
		dst_counter++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	if (dstsize == 0)
		return (src_counter);
	while (src[src_counter] != '\0' && src_counter < freespace)
	{
		dst[dst_counter] = src[src_counter];
		dst_counter++;
		src_counter++;
	}
	dst[dst_counter] = '\0';
	return (dst_len + src_len);
}
