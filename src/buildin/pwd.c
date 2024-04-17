/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:27:14 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/17 13:27:14 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	cwd[64];

	if (getcwd(cwd, 64))
	{
		ft_putendl_fd(cwd, STDOUT);
		return (EXIT_SUCCESS);
	}
	else
	{
		perror("Error from pwd:");
		return (EXIT_FAILURE);
	}
}

int	pwd(char **cmd)
{
	if (ft_strncmp(cmd[0], "pwd", 3) == 0 && cmd[0][3] == '\0')
		return (ft_pwd());
	else
		return (WRONG_ARG);
}
