/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_manage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:54:06 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/05 20:20:13 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list	*envp_list_new(char *key, char *value)
{
	t_env_list	*new;

	new = (t_env_list *)malloc(sizeof(t_env_list));
	if (!new)
	{
		printf("\033[0;31mError:\t\033[0;21mMalloc failed\n\033[0;m");
		exit(MALLOC_ERROR);
	}
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_env_list	*envp_list_add_back(t_env_list *lst, t_env_list *new)
{
	t_env_list	*tmp;

	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lst);
}

void	envp_list_add_front(t_env_list *lst, t_env_list *new)
{
	if (lst && new)
	{
		new->next = lst;
		lst = new;
	}
}
