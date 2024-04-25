/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:38:46 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/12 17:38:46 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h";

int	ft_child_process(t_data *data, t_cmd *node)
{
    og_stdin = dup(STDIN);
    og_stdout = dup(STDOUT);

    ft_redir_fd_std(node->fd_in, STDIN, node->fd_in);
    ft_redir_fd_std(node->fd_out, STDOUT, node->fd_out);
    paths = get_paths(data->envp);
    tmp = abs_bin_path(node->command[0], paths);
    if (!tmp)
        exit(COMMAND_NULL);
	if (execve(tmp, node->command, data->envp) < 0)
    {
        free(tmp);
        ft_free_matrix(paths);
        ft_redir_fds(og_stdin, og_stdout);
        exit(EXIT_FAILURE);
    }
    return (status);
}

void	ft_close_fds(t_cmd *node)
{
    if (node->fd_in != NO_FD && node->fd_in != STDIN)
        close(node->fd_in);
    if (node->fd_out != NO_FD && node->fd_out != STDOUT)
        close(node->fd_out);
}

int	ft_fork_funct(t_data *data, t_cmd *node, int cmd_number)
{
    id = fork();

    if (id == 0)
    {
        if (ft_is_builtin(data, node->command[0]) == TRUE && cmd_number != 0)
        {
            status = ft_builtin(data, node);
            exit (status);
        }
        else
            ft_child_process(data, node);
    }
	else
    {
        waitpid(id, &status, 0);
        ft_close_fds(node);
    }

    return (WEXITSTATUS(status));
}

int	ft_exec_cmd(t_data *data, t_cmd *node, int cmd_number)
{
    if (ft_is_builtin(data, node->command[0]) == TRUE && cmd_number == 0)
    {
        status = ft_builtin(data, node);
        ft_close_fds(node);
        return (status);
    }
    else
    {
        g_batch_flag = 1;
        return (ft_fork_funct(data, node, cmd_number));
    }
}

int	ft_pipex(t_data *data)
{
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
