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

int	ft_echo(char **cmd)
{
    int		i;

    i = 1;
    if (!cmd[1])
    {
        ft_putstr_fd("\n", STDOUT);
        return (EXIT_SUCCESS);
    }
    while (ft_strncmp(cmd[i], "-n", 2) == 0 && cmd[i][2] == '\0')
        i++;
    while (cmd[i])
    {
        ft_putstr_fd(cmd[i], STDOUT);
        i++;
    }
    if (ft_is_nl(cmd) == FALSE)
        write(STDOUT, "\n", 1);
    return (EXIT_SUCCESS);
}

int	echo(char **cmd)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0 && cmd[0][4] == '\0')
		return (ft_echo(cmd));
	else
		return (WRONG_ARG);
}
