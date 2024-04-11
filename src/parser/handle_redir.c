#include "minishell.h"

int handle_pipe(t_cmd *cmd, int *fd_in)
{
    int fd[2];

    if (pipe(fd) == -1)
        return(perror("Pipe error"),1);
    if (cmd->fd_out > 2)
        close(fd[1]);
    else
        cmd->fd_out = fd[1];
    *fd_in = fd[0];
    return (0);
}

int	redir_in(t_token *token,t_cmd *cmd)
{
	if(cmd->fd_out > 2)
		close(cmd->fd_in);
	cmd->fd_out = open(token->next->content,O_RDONLY);
	if(cmd->fd_in == -1)
		return(1);
	token = token->next;
	if (token->next && token->next->key == TKN_PIPE 
		&& !cmd->comand[0] && cmd->fd_in > 2) //en la cmd normal sale por la salida 0
	{
		close(cmd->fd_in);
		cmd->fd_in = 0;
	}
	return(0);
}

int redir_out(t_token *token,t_cmd *cmd)
{
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	cmd->fd_out = open(token->next->content,
						O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->fd_out == -1)
		return(-1);
	token=token->next;
}

