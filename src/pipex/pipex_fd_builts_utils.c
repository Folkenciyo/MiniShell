/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:00:54 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/13 20:00:54 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_builtin(t_data *data, char **cmd)
{
	if (ft_strncmp("cd", cmd[0], 2) == 0 && cmd[0][2] == '\0')
		return (cd(data, cmd));
	else if (ft_strncmp("echo", cmd[0], 4) == 0 && cmd[0][4] == '\0')
		return (echo(data, cmd));
	else if (ft_strncmp("env", cmd[0], 3) == 0 && cmd[0][3] == '\0')
		return (env(data, cmd));
	else if (ft_strncmp("exit", cmd[0], 4) == 0 && cmd[0][4] == '\0')
		return (exit1(data, cmd));
	else if (ft_strncmp("export", cmd[0], 6) == 0 && cmd[0][6] == '\0')
		return (export(data, cmd));
	else if (ft_strncmp("pwd", cmd[0], 3) == 0 && cmd[0][3] == '\0')
		return (pwd(cmd));
	else if (ft_strncmp("unset", cmd[0], 5) == 0 && cmd[0][5] == '\0')
		return (unset(data, cmd));
	return (COMMAND_NULL);
}

void	ft_redir_fd_std(int fd, int std, int fd2)
{
	if (fd != NO_FD && fd != std)
	{
		if (dup2(fd2, std) < 0)
			ft_print_error(REDIR_ERROR);
		close(fd);
	}
}

int	ft_built_in(t_data *data, t_cmd *node)
{
	int	status;
	int	original_fd_out;
	int	original_fd_in;

	original_fd_out = dup(STDOUT);
	original_fd_in = dup(STDIN);
	status = 0;
	ft_redir_fd_std(node->fd_in, STDIN, node->fd_in);
	ft_redir_fd_std(node->fd_out, STDOUT, node->fd_out);
	status = ft_exec_builtin(data, node->command);
	ft_redir_fd_std(node->fd_in, STDIN, original_fd_in);
	ft_redir_fd_std(node->fd_out, STDOUT, original_fd_out);
	return (status);
}

int	ft_cmd_is_built_in(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (data->built_in_cmd[i])
	{
		if (ft_strncmp(str, data->built_in_cmd[i],
				ft_strlen(data->built_in_cmd[i]) + 1) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_list_len(t_cmd *list)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
