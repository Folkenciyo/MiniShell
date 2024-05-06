/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:55:42 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/15 19:55:42 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_matrix(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i])
		{
			free(envp[i]);
			envp[i] = NULL;
		}
		i++;
	}
	free(envp);
	envp = NULL;
}

int	ft_matrix_size(char **envp)
{
	int	size;

	size = 0;
	while (envp[size])
		size++;
	return (size);
}

char	**ft_copy_matrix(char **envp)
{
	int		i;
	char	**new_envp;

	i = 0;
	new_envp = malloc((ft_matrix_size(envp) + 1) * sizeof(char *));
	if (!new_envp)
		return (NULL);
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = NULL;
	ft_free_matrix(envp);
	return (new_envp);
}

int	ft_init_envp(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->envp = (char **)malloc((ft_matrix_size(envp) + 1) * sizeof(char *));
	if (!data)
		return (EXIT_FAILURE);
	while (envp[i])
	{
		data->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	data->envp[i] = NULL;
	return (EXIT_SUCCESS);
}
