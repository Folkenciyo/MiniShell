/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/12 17:38:46 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/12 17:38:46 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process_redir(t_cmd *node)
{
	ft_redir_fd_std(node->fd_in, STDIN, node->fd_in);
	ft_redir_fd_std(node->fd_out, STDOUT, node->fd_out);
}

void error_cmd(char *cmd)
{
    ft_putstr_fd("bash: Command not found: ",2);
    ft_putstr_fd(cmd,2);
    ft_putstr_fd("\n",2);
    exit(COMMAND_NULL);
}



int	ft_child_process(t_data *data, t_cmd *node)
{
	int		og_stdin;
	int		og_stdout;
	char	*tmp;
	int		status;
	char	**paths;

	tmp = NULL;
	paths = NULL;
	status = 0;
	og_stdin = dup(STDIN);
	og_stdout = dup(STDOUT);
	child_process_redir(node);
	paths = get_paths(data->envp);
	tmp = abs_bin_path(node->command[0], paths);
	if (!tmp)
		// exit(COMMAND_NULL);
	if (execve(tmp, node->command, data->envp) < 0)
	{
        free(tmp);
		ft_free_matrix(paths);
		ft_redir_fd_std(og_stdin, status, og_stdout);
		error_cmd(node->command[0]);
		exit(EXIT_FAILURE);
	}
	return (status);
}

int	ft_fork(t_data *data, t_cmd *node, int cmd_number)
{
	int		status;
	pid_t	id;

	status = NO_FD;
	id = fork();
	if (id == 0)
	{
		if (ft_is_builtin(data, node->command[0]) == TRUE && cmd_number != 0)
		{
			status = ft_built_in(data, node);
			exit(status);
		}
		else
			ft_child_process(data, node);
	}
	else
	{
		waitpid(id, &status, 0);
		if (node->fd_in != NO_FD && node->fd_in != STDIN)
			close(node->fd_in);
		if (node->fd_out != NO_FD && node->fd_out != STDOUT)
			close(node->fd_out);
	}
	return (WEXITSTATUS(status));
}

int	ft_exec_cmd(t_data *data, t_cmd *node, int cmd_number)
{
	int	status;

	status = 0;
	if (ft_is_builtin(data, node->command[0]) == TRUE && cmd_number == 0)
	{
		status = ft_built_in(data, node);
		if (node->fd_in != NO_FD && node->fd_in != STDIN)
			close(node->fd_in);
		if (node->fd_out != NO_FD && node->fd_out != STDOUT)
			close(node->fd_out);
		return (status);
	}
	else
	{
		g_batch_flag = 1;
		return (ft_fork(data, node, cmd_number));
	}
}

int	ft_pipex(t_data *data)
{
	t_cmd	*list;
	int		status;
	int		cmd_number;

	list = data->cmd_list;
	status = 0;
	cmd_number = 0;
	if (ft_lstsize_cmd(list) > 1)
		cmd_number = 1;
	while (list)
	{
		status = ft_exec_cmd(data, list, cmd_number);
		g_batch_flag = 0;
		data->status = status;
		list = list->next;
		cmd_number++;
	}
	return (EXIT_SUCCESS);
}
