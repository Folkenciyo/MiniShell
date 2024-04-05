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

#include "minishell.h"

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
		status = ft_exec_cmd(data, list, cmd_number); // Ejecuta el comando actual y guarda el estado
		g_batch_flag = 0; // Asigna 0 a la variable global g_batch_flag
		data->status = status; // Asigna el estado a la propiedad status de la estructura data
		list = list->next; // Avanza al siguiente elemento en la lista de comandos
		cmd_number++; // Incrementa el contador de comandos
	}
	return (EXIT_SUCCESS); // Retorna EXIT_SUCCESS (generalmente 0) al finalizar
}

/* NECESARIO PARA PROBAR ES TOTALMENTE TEMPORAL */
char	**ft_get_path(char **envp, char *cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_strtrim(envp[i] + 5, ":");
			path = ft_split(tmp, ':');
			free(tmp);
			return (path);
		}
		i++;
	}
	return (NULL);
}

t_cmd	*ft_cmd_lst_new(t_cmd *cmd_lst, char **argv, char **envp)
{
	t_cmd	*new_cmd;
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = cmd_lst;
	while (argv[i])
	{
		new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!new_cmd)
			exit(MALLOC_ERROR);
		new_cmd->comand = ft_split(argv[i], ' ');
		new_cmd->choosen_path = ft_get_path(envp, new_cmd->comand[0]);
		new_cmd->fd_in = NULL;
		new_cmd->fd_out = NULL;
		new_cmd->next = NULL;
		if (!cmd_lst)
			cmd_lst = new_cmd;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_cmd;
		}
		i++;
	}
	return (cmd_lst);
}

int t_data_example_for_pipex(int argc, char **argv, char **envp)
{
	t_cmd *cmd_lst=NULL;
	cmd_lst = ft_cmd_lst_new(cmd_lst, argv, envp);
	t_data data;
	data.cmd_lst = cmd_lst;
	ft_pipex(&data);

	return (EXIT_SUCCESS);
}

/* NECESARIO PARA PROBAR ES TOTALMENTE TEMPORAL */
char	**ft_get_path(char **envp, char *cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_strtrim(envp[i] + 5, ":");
			path = ft_split(tmp, ':');
			free(tmp);
			return (path);
		}
		i++;
	}
	return (NULL);
}

t_cmd	*ft_cmd_lst_new(t_cmd *cmd_lst, char **argv, char **envp)
{
	t_cmd	*new_cmd;
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = cmd_lst;
	while (argv[i])
	{
		new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!new_cmd)
			exit(MALLOC_ERROR);
		new_cmd->comand = ft_split(argv[i], ' ');
		new_cmd->choosen_path = ft_get_path(envp, new_cmd->comand[0]);
		new_cmd->fd_in = NULL;
		new_cmd->fd_out = NULL;
		new_cmd->next = NULL;
		if (!cmd_lst)
			cmd_lst = new_cmd;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_cmd;
		}
		i++;
	}
	return (cmd_lst);
}

int t_data_example_for_pipex(int argc, char **argv, char **envp)
{
	t_cmd *cmd_lst=NULL;
	cmd_lst = ft_cmd_lst_new(cmd_lst, argv, envp);
	t_data data;
	data.cmd_lst = cmd_lst;
	ft_pipex(&data);

	return (EXIT_SUCCESS);
}