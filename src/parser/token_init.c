/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:15:41 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/23 14:35:13 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_token(t_data *data, int key, char *value)
{
	t_token	*token;

	token = ft_tokennew(key, value);
	if(!token)
		return ;
	if (!data->token_list)
		ft_tokenadd_front(&data->token_list, token);
	else
		ft_tokenadd_back(&data->token_list, token);
}

int	token_maker(t_data *data, char *str)
{
	char	*tmp;
	int		quotes;
	
	tmp = str;
	quotes = 0;
	while (*tmp)
	{
		if (!special_chars(*tmp))
			word_handler(data, &tmp);
		else if (*tmp == '>' || *tmp == '<')
			redir_handler(data, &tmp);
		else if (*tmp == '\'' || *tmp == '\"')
			quotes = quotes_handler(data, &tmp);
		else if (*tmp == '|')
			fill_token(data, TKN_PIPE, "|");
		tmp++;
	}
	if (quotes)
		return (free_token(&data->token_list), free(str), 1);
	return (0);
}

void	print_token(t_data *data)
{
	t_token	*token;

	token = data->token_list;
	while (token)
	{
		printf("key : %d\n", token->key);
		printf("content : %s\n", token->content);
		printf("len : %d\n", token->len);
		printf("--------------------------------------------\n");
		token = token->next;
	}
}
