/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:37 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/08 20:19:18 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_pipe(t_cmd *cmd, int *fd_in)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (perror("Pipe error"), 1);
	if (cmd->fd_out > 2)
		close(fd[1]);
	else
		cmd->fd_out = fd[1];
	*fd_in = fd[0];
	return (0);
}

int	redir_in(t_token *token, t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	cmd->fd_in = open(token->next->content, O_RDONLY);
	if (cmd->fd_in == -1)
		return (1);
	token = token->next;
	if (token->next && token->next->key == TKN_PIPE && !cmd->command[0]
		&& cmd->fd_in > 2)
	{
		close(cmd->fd_in);
		cmd->fd_in = 0;
	}
	return (0);
}

int	redir_out(t_token *token, t_cmd *cmd)
{
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	if (token->key == TKN_REDIR_OUT)
		cmd->fd_out = open(token->next->content,
				O_WRONLY | O_CREAT | O_TRUNC,
				0644);
	else
	{
		cmd->fd_out = open(token->next->content,
				O_WRONLY | O_CREAT | O_APPEND,
				0644);
	}
	if (cmd->fd_out == -1)
		return (1);
	token = token->next;
	return (0);
}

int	handle_redirections(t_cmd *cmd, int *fd_in, t_token **token)
{
	if (*fd_in != 0)
	{
		cmd->fd_in = *fd_in;
		*fd_in = 0;
	}
	if ((*token)->key == TKN_PIPE)
		return (handle_pipe(cmd, fd_in));
	else if ((*token)->key == TKN_REDIR_IN)
		return (redir_in(*token, cmd));
	else if ((*token)->key == TKN_REDIR_OUT
		|| (*token)->key == TKN_REDIR_APPEND)
		return (redir_out(*token, cmd));
	else if ((*token)->key == TKN_REDIR_SOURCE)
		return (here_doc_status(cmd, *token));
	return (0);
}
