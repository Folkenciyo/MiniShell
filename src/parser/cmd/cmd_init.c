/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:12 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/07 22:46:26 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->command = ft_calloc(1, sizeof(char *));
	node->command[0] = NULL;
	node->fd_in = 0;
	node->fd_out = 1;
	node->next = NULL;
	return (node);
}

void	add_cmd_back(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	if (*cmd == NULL)
	{
		tmp = NULL;
		*cmd = new_cmd;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
}

void	print_cmd(t_cmd *cmd)
{
	int	i;

	while (cmd)
	{
		i = 0;
		while (cmd->command[i])
		{
			printf("comand[%d]: %s\n", i, cmd->command[i]);
			i++;
		}
		printf("fd_in: %d\n", cmd->fd_in);
		printf("fd_out: %d\n", cmd->fd_out);
		cmd = cmd->next;
	}
}