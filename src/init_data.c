/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:01:53 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/25 15:16:19 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env_list(t_data *data, char **envp)
{
	t_env_list	*new;
	t_env_list	*tmp;
	char		*delimiter;
	int			i;

	i = 0;
	while (envp[i])
	{
		new = (t_env_list *)malloc(sizeof(t_env_list));
		if (!new)
		{
			printf("\033[0;31mError:\t\033[0;21mMalloc failed\n\033[0;m");
			exit(1);
		}
		delimiter = ft_strchr(envp[i], '=');
		new->key = ft_substr(envp[i], 0, delimiter - envp[i]);
		new->value = ft_strdup(delimiter + 1);
		new->next = NULL;
		if (!data->envp_list)
			data->envp_list = new;
		else
		{
			tmp = data->envp_list;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		i++;
	}
}

void	init_env(t_data *data, char **envp)
{
	char	**tmp;
	int		count;
	int		i;

	count = 0;
	tmp = envp;
	while (*tmp)
	{
		count++;
		tmp++;
	}
	data->envp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!data->envp)
	{
		printf("\033[0;31mError:\t\033[0;21mMalloc failed\n\033[0;m");
		exit(1);
	}
	i = 0;
	while (i < count)
	{
		data->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	data->envp[i] = NULL;
}

int	build_in_data(t_data *data)
{
	data->built_in_cmd[0] = ft_strdup("echo");
	data->built_in_cmd[1] = ft_strdup("cd");
	data->built_in_cmd[2] = ft_strdup("pwd");
	data->built_in_cmd[3] = ft_strdup("export");
	data->built_in_cmd[4] = ft_strdup("unset");
	data->built_in_cmd[5] = ft_strdup("env");
	data->built_in_cmd[6] = ft_strdup("exit");
	data->built_in_cmd[7] = NULL;
	return (0);
}

int	init_data(t_data *data, char **envp)
{
	build_in_data(data);
	data->status = 0;
	data->exit = 0;
	data->envp_list = NULL;
	data->cmd_list = NULL;
	init_env(data, envp);
	init_env_list(data, envp);
	return (0);
}
