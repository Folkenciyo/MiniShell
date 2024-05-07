/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/04/08 11:56:16 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/08 11:56:16 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_dirs(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
}

int	ft_cd(t_data *data, char **cmd)
{
	if (cmd[1] == NULL)
		return (ft_cd_home(data));
	else if (ft_strncmp(cmd[1], "-", 1) == 0)
	{
		if (cmd[1][1] == '\0')
			return (ft_cd_lastdir(data));
		else
			return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(cmd[1], "~", 1) == 0)
	{
		if (ft_strlen(cmd[1]) == 1)
			return (ft_cd_home(data));
		else if (ft_strlen(cmd[1]) > 1)
			return (ft_cd_home_relat(data, cmd[1]));
	}
	else if (ft_strncmp(cmd[1], "..", 2) == 0)
		return (ft_cd_other(data, cmd[1]));
	else if (ft_strncmp(cmd[1], ".", 1) == 0)
		return (ft_cd_other(data, cmd[1]));
	else if (ft_strncmp(cmd[1], "/", 1) == 0)
		return (ft_cd_other(data, cmd[1]));
	else
		return (ft_cd_other(data, cmd[1]));
	return (EXIT_FAILURE);
}

int	cd(t_data *data, char **cmd)
{
	int	status;

	status = 0;
	if (ft_strncmp(cmd[0], "cd", 2) == 0 && cmd[0][2] == '\0')
	{
		status = ft_cd(data, cmd);
		refill_envp_lst(data, data->envp);
		return (status);
	}
	else
	{
		ft_putendl_fd("cd: command not found", WRONG_ARG);
		return (COMMAND_NULL);
	}
}
