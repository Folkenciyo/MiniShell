#include "minishell.h"

//Basicamente una funcion para gestionar el error de unexpected token
int	unexpected_token(t_token *token)
{
	if (token && token->key == TKN_PIPE)
		return(256); //para que no salga por ninguna salida de error
	while (token->next)
	{
		if ((token->key == TKN_PIPE 
			|| token->key == TKN_REDIR_APPEND
			|| token->key == TKN_REDIR_IN
			|| token->key == TKN_REDIR_OUT
			|| token->key == TKN_REDIR_SOURCE
			)&& (!token->next || (token->next && token->next->key != TKN_WORD)))
				return(269);
		token = token->next;
	}
	return(0);
}

char	**add_to_comand(char **arr, char *new_str)
{
	size_t	i;
	size_t	j;
	char	**new_arr;

	i = 0;
	j = 0;
	while (arr && arr[i])
		i++;
	new_arr = ft_calloc(i + 2, sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (j < i)
	{
		new_arr[j] = arr[j];
		j++;
	}
	new_arr[i] = new_str;
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}

int	redir_out_last(t_token *token)
{
	while (token->next)
	{
		if ((token->key == TKN_REDIR_OUT|| token->key == TKN_REDIR_APPEND)
				&& (token->next && !token->next->next))
			return(1);
		token = token->next;
	}
	return(0);
}

void change_cmd_out(t_cmd *cmd)
{
	while (cmd->next)
	{
		if (!cmd->next)
		{
			if (cmd->fd_out > 2)
			{
				close(cmd->fd_out);
				cmd->fd_out = 1;
			}
		}
		cmd = cmd->next;
	}
}