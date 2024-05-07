/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:17 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/05 20:02:18 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unexpected_token(t_token *token)
{
	if (token && token->key == TKN_PIPE)
		return (258);
	while (token)
	{
		if ((token->key == TKN_PIPE || token->key == TKN_REDIR_APPEND
				|| token->key == TKN_REDIR_IN || token->key == TKN_REDIR_OUT
				|| token->key == TKN_REDIR_SOURCE) && (!token->next
				|| (token->next && token->next->key != TKN_WORD)))
			return (258);
		token = token->next;
	}
	return (0);
}

char	**add_to_command(char **arr, char *new_str)
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
	while (token)
	{
		if ((token->key == TKN_REDIR_OUT || token->key == TKN_REDIR_APPEND)
			&& (token->next && !token->next->next))
			return (1);
		token = token->next;
	}
	return (0);
}

void	change_cmd_out(t_cmd *cmd)
{
	while (cmd)
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

int	status_check(int status)
{
	if (status == 258)
		return (printf("bash: syntax error near unexpected token\n"), status);
	else if (status == 1)
		return (printf("bash: syntax error no such a file or directory\n"),
			status);
	return (0);
}
