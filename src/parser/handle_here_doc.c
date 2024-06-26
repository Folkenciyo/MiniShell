/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:34 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/08 20:17:06 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	here_doc(t_cmd *cmd, char *here_doc)
{
	char	*input;
	int		fd[2];

	input = NULL;
	if (!here_doc || pipe(fd) < 0)
		return (-1);
	while (3)
	{
		input = readline("> ");
		if (!input
			|| (input && !ft_strncmp(input, here_doc, ft_strlen(here_doc))))
			break ;
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
	free(input);
	close(fd[1]);
	cmd->fd_in = fd[0];
	return (0);
}

int	here_doc_status(t_cmd *cmd, t_token *token)
{
	if (here_doc(cmd, token->next->content) == -1)
		return (-1);
	token = token->next;
	return (0);
}
