/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:38:25 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/17 13:38:25 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_delete_variable(t_data *data, char *tuple)
{
	char	**new_envp;
	int		i;
	int		j;

	new_envp = malloc(ft_matrix_size(data->envp) * sizeof(char *));
	i = 0;
	j = 0;
	while (data->envp[j])
	{
		if (ft_contains(data->envp[j], tuple) == FALSE)
		{
			new_envp[i] = ft_strdup(data->envp[j]);
			i++;
		}
		j++;
	}
	new_envp[i] = NULL;
	ft_free_matrix(data->envp);
	data->envp = ft_copy_matrix(new_envp);
	return ;
}

int	ft_unset(t_data *data, char *tuple)
{
	if (ft_env_exists(tuple, data->envp) == TRUE)
	{
		ft_delete_variable(data, tuple);
		refill_envp_lst(data, data->envp);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_SUCCESS);
}

int	unset(t_data *data, char **cmd)
{
	if (ft_strncmp(cmd[0], "unset", 5) == 0 && cmd[0][5] == '\0')
	{
		if (cmd[1])
			return (ft_unset(data, cmd[1]));
		else
			return (EXIT_SUCCESS);
	}
	else
		return (ft_print_error("Bad command"));
}
