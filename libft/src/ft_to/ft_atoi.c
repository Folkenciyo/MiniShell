/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:24:53 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/25 20:24:54 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static void	is_int(long int res)
{
	if (res > 2147483647 || res < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(2);
	}
}

long int	ft_atoi(const char *nptr)
{
	long int	res;
	int			neg;

	res = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			neg = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	res = res * neg;
	is_int(res);
	return (res);
}
