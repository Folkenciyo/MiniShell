/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupla_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:34:12 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/15 20:34:12 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_contains(char *envp_tuple, char *tuple)
{
	int	size;

	size = ft_var_size(tuple);
	if (ft_strncmp(envp_tuple, tuple, size) == 0
		&& ((envp_tuple[size] == '=') || (envp_tuple[size] == '\0')))
		return (TRUE);
	else
		return (FALSE);
}

int	ft_env_exists(char *tuple, char **envp)
{
	int	idx;

	idx = 0;
	while (envp[idx])
	{
		if (ft_contains(envp[idx], tuple) == TRUE)
			return (TRUE);
		idx++;
	}
	return (FALSE);
}
