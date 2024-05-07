/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:02:20 by pjimenez          #+#    #+#             */
/*   Updated: 2024/05/05 20:02:20 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(t_data *data, char **input)
{
	char	*value;
	char	*key;

	key = NULL;
	value = NULL;
	(*input)++;
	if (**input == '?')
	{
		value = ft_itoa(data->status);
		(*input)++;
	}
	else if (ft_isalpha(**input) || **input == '_' || ft_isdigit(**input))
	{
		key = envp_key(*input);
		value = envp_value(data, key);
		if (!value)
			value = ft_strdup("");
		(*input) += ft_strlen(key);
		free(key);
	}
	return (value);
}

char	*process_value(t_data *data, t_token *token, char *value, int *len)
{
	char	*new_str;
	char	*result;

	new_str = (char *) malloc(token->len + 1);
	if (!new_str)
		return (NULL);
	new_str[token->len] = '\0';
	while (*value)
	{
		if (*value == '$' && valid_key(*(value + 1)))
		{
			result = get_env_value(data, &value);
			if (result != NULL)
				append_env_value(new_str, result, len);
		}
		else
		{
			new_str[*len] = *value;
			(*len)++;
			value++;
		}
	}
	return (new_str);
}

int	get_new_len(t_data *data, char *content)
{
	int		len;
	char	*value;

	value = NULL;
	len = 0;
	while (*content)
	{
		if (*content == '$' && *(content + 1) && valid_key(*(content + 1)))
		{
			value = get_env_value(data, &content);
			len += ft_strlen(value);
		}
		else
		{
			len++;
			content++;
		}
	}
	return (len);
}

char	*get_new_value(t_data *data, t_token *token)
{
	char	*value;
	char	*new_value;
	int		len;

	len = 0;
	value = token->content;
	new_value = process_value(data, token, value, &len);
	free(value);
	return (new_value);
}

void	expand(t_data *data)
{
	t_token	*token;

	token = data->token_list;
	while (token)
	{
		if (token->key == TKN_WORD || token->key == TKN_DQUOTES)
		{
			token->len = get_new_len(data, token->content);
			token->content = get_new_value(data, token);
		}
		if (token->key == TKN_DQUOTES || token->key == TKN_SQUOTES)
			token->key = TKN_WORD;
		token = token->next;
	}
}
