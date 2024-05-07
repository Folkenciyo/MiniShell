/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:14:22 by pjimenez          #+#    #+#             */
/*   Updated: 2024/04/03 21:16:50 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(str);
	if (len < n)
		n = len;
	dest = (char *)malloc(n + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str, n);
	dest[n] = '\0';
	return (dest);
}
