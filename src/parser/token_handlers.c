/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:47 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/08 20:18:06 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	space_handler(t_data *data, char **str)
{
	char	*tmp;
	char	*start;

	start = *str;
	while (is_space(*(*str + 1)))
	{
		(*str)++;
	}
	tmp = ft_strndup(start, *str + 1 - start);
	fill_token(data, TKN_SP, tmp);
	free(tmp);
}

void	word_handler(t_data *data, char **str)
{
	char	*start;
	char	*tmp;

	tmp = NULL;
	if (!special_chars(**str) || (*(*str + 1) && **str == '&' && *(*str
				+ 1) != '&'))
	{
		start = *str;
		while (*(*str + 1) && (!special_chars(*(*str + 1)) || (**str == '&'
					&& *(*str + 1) != '&')))
			(*str)++;
		tmp = ft_strndup(start, *str + 1 - start);
		fill_token(data, TKN_WORD, tmp);
	}
	free(tmp);
}

void	redir_handler(t_data *data, char **str)
{
	if (**str == '>')
	{
		if (ft_strncmp(*str, ">>", 2) == 0)
		{
			fill_token(data, TKN_REDIR_APPEND, ">>");
			(*str)++;
		}
		else
			fill_token(data, TKN_REDIR_OUT, ">");
	}
	else if (**str == '<')
	{
		if (ft_strncmp(*str, "<<", 2) == 0)
		{
			fill_token(data, TKN_REDIR_SOURCE, "<<");
			(*str)++;
		}
		else
			fill_token(data, TKN_REDIR_IN, "<");
	}
}

int	quotes_handler(t_data *data, char **str)
{
	char	*tmp;
	char	*start;
	char	quote;

	tmp = NULL;
	quote = **str;
	start = ++(*str);
	while (**str && **str != quote)
		(*str)++;
	if (**str == quote)
	{
		tmp = ft_strndup(start, *str - start);
		if (quote == '\"')
			fill_token(data, TKN_DQUOTES, tmp);
		else if (quote == '\'')
			fill_token(data, TKN_SQUOTES, tmp);
		free(tmp);
	}
	else
		return (printf("Quotes are not closed\n"), 1);
	return (0);
}
