/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:30:56 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/27 17:30:56 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int	ft_is_nl(char **str)
{
	if (!str[1])
		return (FALSE);
	if (ft_strncmp(str[1], "-n", 2) == 0 && str[1][2] == '\0')
		return (TRUE);
	return (FALSE);
}

int	ft_echo(t_cmd *cmd_list, char **cmd)
{
	int		idx;
    t_cmd   *tmp;

    tmp = cmd_list;
	idx = 1;

    tmp = tmp->next;
    printf("msg: %s\n", tmp->command[0]);
	if (!cmd[1])
	{
		ft_putstr_fd("\n", STDOUT);
		return (EXIT_SUCCESS);
	}
	while (ft_strncmp(cmd[idx], "-n", 2) == 0 && cmd[idx][2] == '\0')
		idx++;
	while (cmd[idx])
	{
        printf("cmd[%d]: %s\n", idx, cmd[idx]);
		ft_putstr_fd(cmd[idx], STDOUT);
		idx++;
	}
    printf("cmd[%d]: %s\n", idx, cmd[idx]);
	if (ft_is_nl(cmd) == FALSE)
		write(STDOUT, "\n", 1);
	return (EXIT_SUCCESS);
}

int	echo(t_data *data, char **cmd)
{
    printf("hello");
	if (ft_strncmp(cmd[0], "echo", 4) == 0 && cmd[0][4] == '\0')
		return (ft_echo(data->cmd_list, cmd));
	else
		return (WRONG_ARG);
}