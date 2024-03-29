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
