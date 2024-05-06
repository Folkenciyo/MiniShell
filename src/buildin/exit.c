/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:56:05 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/17 11:56:05 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static int	ft_isnum(char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (FALSE);
	while (str[size] != '\0')
	{
		if (ft_isdigit(str[size]) == FALSE)
			return (FALSE);
		size++;
	}
	return (TRUE);
}

int	ft_exit(t_data *data, int option)
{
	int	value;

	value = option % 256;
	data->status = value;
	data->exit = 1;
	return (value);
}

int	exit1(t_data *data, char **cmd)
{
	ft_putendl_fd("exit", STDOUT);
	if (ft_strncmp(cmd[0], "exit", 4) == 0 && cmd[0][4] == '\0')
	{
		if (!cmd[1])
			return (ft_exit(data, 0));
		else if (ft_isnum(cmd[1]) == FALSE)
		{
			ft_putendl_fd("Bash: exit: numeric argument required", 2);
			return (ft_exit(data, 255));
		}
		else if (cmd[1] && cmd[2] != NULL)
		{
			ft_putendl_fd("Bash: exit: too many arguments", 2);
			return (EXIT_FAILURE);
		}
		else
			return (ft_exit(data, ft_atoi(cmd[1])));
	}
	else
	{
		ft_print_error("Bad command");
		return (WRONG_ARG);
	}
}
