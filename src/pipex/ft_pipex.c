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

int	ft_exec_cmd(t_data *data, t_cmd *list, int cmd_number)
{
	int	status;

	status = 0;
	if (!list->comand[0])
		return (COMMAND_NULL);
	else if (ft_cmd_is_built_in(data, list->comand[0]) == TRUE
		&& cmd_number == 0)
	{
		status = ft_built_in(data, list->comand);
		ft_close_fd(list);
		return (status);
	}
/* 	else
	{
		g_batch_flag = 1;
		return (ft_fork(data, list, cmd_number));
	}*/
	return (status);
}

int	ft_pipex(t_data *data)
{
	t_cmd	*list;
	int		status;
	int		cmd_number;

	list = data->cmd_lst;
	status = 0;
	cmd_number = 0;
	if (ft_lst_size(list) > 1)
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
