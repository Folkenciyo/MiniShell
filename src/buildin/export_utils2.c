/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:29:34 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/15 20:29:34 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	ft_empty_line(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (TRUE);
	while (string[i])
		i++;
	if (i == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	ft_double_assign(char *str)
{
	int	i;
	int	control;

	i = 0;
	control = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			control++;
		i++;
	}
	if (control > 1)
		return (TRUE);
	return (FALSE);
}

char	**ft_init_matrix_nil(int size)
{
	char	**matrix;
	int		i;

	matrix = malloc((size + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		matrix[i] = NULL;
		i++;
	}
	return (matrix);
}

int	ft_max_len(char *str1, char *str2)
{
	int	size1;
	int	size2;

	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	if (size1 > size2)
		return (size1);
	else
		return (size2);
}

int	ft_not_in_matrix(char *string, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], string, ft_max_len(envp[i], string)) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
