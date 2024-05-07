/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:40 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/05 20:02:40 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	special_chars(char c)
{
	if (c == '\"' || c == '\'' || c == '>' || c == '<' || is_space(c)
		|| c == '|')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}
