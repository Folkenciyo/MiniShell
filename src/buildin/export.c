/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:08:54 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/12 19:08:54 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_export(t_data *data)
{
    int		i;
    char	**ordered_list;

    i = 0;
    if (data->envp == NULL)
        return ;
    ordered_list = ft_order_env(data->envp);
    while (ordered_list[i] != NULL)
    {
        if (ft_empty_line(ordered_list[i]) == TRUE)
            i++;
        else
        {
            printf("declare -x %s\n", ordered_list[i]);
            i++;
        }
    }
    // Libera la memoria utilizada por la lista ordenada.
    ft_free_matrix(ordered_list);
}

int	ft_export(t_data *data, char *tuple)
{
    if (!tuple)
    {
        ft_print_export(data);
        return (EXIT_SUCCESS);
    }
    if (ft_double_assign(tuple) == TRUE)
        return (EXIT_SUCCESS);
    if (ft_env_exists(tuple, data->envp) == TRUE)
    {
        ft_modify_variable(data->envp, tuple);
        refill_envp_lst(data, data->envp);
    }
    else
    {
        data->envp = ft_add_to_matrix(data->envp, tuple);
        refill_envp_lst(data, data->envp);
    }
    return (EXIT_SUCCESS);
}

int	export(t_data *data, char **cmd)
{
    if (ft_strncmp(cmd[0], "export", 6) == 0 && cmd[0][6] == '\0')
    {
        if (!cmd[1])
            return (ft_export(data, NULL));
        else
            return (ft_export(data, cmd[1]));
    }
    else
        return (ft_print_error("Wrong command\n"));
}
