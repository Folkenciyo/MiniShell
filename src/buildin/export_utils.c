/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:53:08 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/15 19:53:08 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_str_comparator(void)
{
    char	*string;

    string = malloc (2 * sizeof(char));
    if (!string)
        return (NULL);
    string[0] = 127;
    string[1] = '\0';
    return (string);
}

char	*ft_find_min_str(char **envp, char **new_envp)
{
    char	*tmp;
    int		i;

    tmp = ft_str_comparator();
    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(tmp, envp[i], ft_max_len(tmp, envp[i])) > 0
            && ft_not_in_matrix(envp[i], new_envp) == TRUE)
        {
            free (tmp);
            tmp = ft_strdup(envp[i]);
        }
        i++;
    }
    return (tmp);
}

char	**ft_order_env(char **envp)
{
    char	**new_envp;
    int		size;
    int		i;

    size = ft_matrix_size(envp);
    new_envp = ft_init_matrix_nil(size);
    if (!envp)
        return (NULL);
    i = 0;
    while (i < size)
    {
        new_envp[i] = ft_find_min_str(envp, new_envp);
        i++;
    }
    new_envp[i] = NULL;
    return (new_envp);
}

void	ft_modify_variable(char **envp, char *tuple)
{
    int	i;

    i = 0;

    while (envp[i])
    {
        if (ft_contains(tuple, envp[i]) == TRUE)
        {
            free(envp[i]);
            envp[i] = ft_strdup(tuple);
            return ;
        }
        i++;
    }
    return ;
}

char	**ft_add_to_matrix(char **envp, char *tuple)
{
    char	**new_envp;
    int		i;

    new_envp = malloc((ft_matrix_size(envp) + 2) * sizeof(char *));
    i = 0;
    while (envp[i])
    {
        new_envp[i] = ft_strdup(envp[i]);
        i++;
    }
    new_envp[i] = ft_strdup(tuple);
    new_envp[++i] = NULL;
    ft_free_matrix(envp);
    return (new_envp);
}
