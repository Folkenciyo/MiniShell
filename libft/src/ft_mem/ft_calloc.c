/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:22:40 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/25 22:22:43 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ret;

	ret = (void *)malloc(nitems * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, nitems * size);
	return (ret);
}
