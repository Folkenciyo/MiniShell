/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupla_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/04/12 18:05:58 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/12 18:05:58 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_var_exists(char *variable, char *envp_tuple)
{
	int	size;

	size = ft_strlen(variable);
	if (ft_strncmp(envp_tuple, variable, size) == 0
		&& (envp_tuple[size] == '='))
		return (TRUE);
	else
		return (FALSE);
}

char	*ft_store_value(char *tuple)
{
	char	*value;
	int		i;

	value = NULL;
	i = 0;
	while (tuple[i] != '=' && tuple[i] != '\0')
		i++;
	i++;
	if (tuple[i] == '\0')
		return (NULL);
	value = ft_substr(tuple, i, ft_strlen(tuple) - i);
	return (value);
}

char	*ft_get_env_value(t_data *data, char *key)
{
	char	*tmp_env;
	int		i;

	tmp_env = NULL;
	i = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_var_exists(key, data->envp[i]) == TRUE)
		{
			tmp_env = ft_store_value(data->envp[i]);
			return (tmp_env);
		}
		i++;
	}
	return (NULL);
}

int	ft_var_size(char *tuple)
{
	int	i;

	i = 0;
	while (tuple[i] != '=' && tuple[i] != '\0')
		i++;
	return (i);
}
