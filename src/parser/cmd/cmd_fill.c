/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:05 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/08 20:21:45 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_cmd_if(t_cmd **cmd_lst, t_cmd **new, t_token *token)
{
	if (!*new || (*new && (*new)->command[0] && (token->key == TKN_WORD)))
	{
		*new = new_cmd();
		add_cmd_back(cmd_lst, *new);
	}
}

void	add_word_cmd(t_cmd **new, t_token **token, int *status, int *fd_in)
{
	while (*token && ((*token)->key == TKN_WORD))
	{
		(*new)->command = add_to_command((*new)->command, (*token)->content);
		if ((*token)->key == TKN_WORD)
		{
			if (!(*token)->next && handle_redirections(*new, fd_in, token))
			{
				*status = 1;
				break ;
			}
		}
		*token = (*token)->next;
	}
}

void	cmd_create(t_data *data)
{
	t_cmd	*new;
	t_token	*token;
	int		fd_in;
	int		status;

	new = NULL;
	fd_in = 0;
	token = data->token_list;
	status = unexpected_token(token);
	token_jumper(&token);
	while (token && !status)
	{
		new_cmd_if(&data->cmd_list, &new, token);
		add_word_cmd(&new, &token, &status, &fd_in);
		if (token && handle_redirections(new, &fd_in, &token))
		{
			status = 1;
			break ;
		}
		else if (token)
			token = token->next;
	}
	if (!redir_out_last(data->token_list))
		change_cmd_out(data->cmd_list);
	data->status = status_check(status);
}
