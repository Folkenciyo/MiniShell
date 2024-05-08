/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:48:28 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/08 18:17:56 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	console_init(t_data *data)
{
	char	*input;

	while (data->exit != 1)
	{
		signals_call();
		input = readline(ft_strjoin(getenv("USER"), "$ "));
		if (!input)
		{
			free(input);
			printf("exit\n");
			data->exit = 1;
			continue ;
		}
		if (token_maker(data, input))
			continue ;
		expand(data);
		cmd_create(data);
		ft_pipex(data);
		if (*input != '\0')
			add_history(input);
		restore_lists(&data, input);
	}
	clear_history();
}
