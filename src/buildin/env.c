/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:47:48 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/16 20:47:48 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_env(t_data *data)
{
	char	*value;
	int		i;

	value = NULL;
	i = 0;
	if (data->envp == NULL)
		return (EXIT_SUCCESS);
	while (data->envp[i])
	{
		value = ft_store_value(data->envp[i]);
		if (value != NULL)
			printf("%s\n", data->envp[i]);
		i++;
		free(value);
		value = NULL;
	}
	if (value)
		free(value);
	return (EXIT_SUCCESS);
}

int	env(t_data *data, char **cmd)
{
	if (cmd[1])
	{
		ft_print_error("env");
		return (COMMAND_NULL);
	}
	else if (ft_strncmp(cmd[0], "env", 3) == 0 && cmd[0][3] == '\0')
		return (ft_env(data));
	else
	{
		ft_putendl_fd("Bad command", WRONG_ARG);
		return (WRONG_ARG);
	}
}
