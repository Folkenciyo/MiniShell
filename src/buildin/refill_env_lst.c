/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_env_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:35:22 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/16 20:35:22 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_t_lstclear(t_env_list **envp_lst)
{
	t_env_list	*current;
	t_env_list	*next;

	current = *envp_lst;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	*envp_lst = NULL;
}

void	refill_envp_lst(t_data *data, char **new_envp)
{
	(void)new_envp;
	if (data->envp_list)
		ft_t_lstclear(&data->envp_list);
	//init_envp_lst(data, new_envp); //la necesito de las signals

}
