/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:02:06 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/05 20:12:41 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	//int		status;

	(void)argv;
	if (argc != 1)
		return (printf("\033[0;31mError:\t\033[0;21mToo many arguments\n\033[0;m"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("\033[0;31mError:\t\033[0;21mMalloc failed\n\033[0;m"));
	init_data(data, envp);
	return (0);
}
