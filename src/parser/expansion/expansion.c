
#include "minishell.h"

char	*get_env_value(t_data *data, char *input)
{
	char	*value;
	char	*key;

	key = NULL;
	value = NULL;
	// (*input)++;
	if (*input == '?')
	{
		value = ft_itoa(data->status);
		input++;
	}
	else if (ft_isalpha(*input) || *input == '_' || ft_isdigit(*input))
	{
		key = envp_key(input);
		
		value = envp_value(data, key);
		if (!value)
			return ("");
		input += ft_strlen(key);
	}
	free(key);
	return (value);
}

void	change_token_value(t_data *data, char *key, char *value)
{
	t_token	*token;

	token = data->token_list;
	if (token->content && !ft_strncmp(token->content, key,
			ft_strlen(key)))
	{
		token->content = ft_strdup(value);
		token->len = ft_strlen(token->content);
	}
	if (token->key == TKN_DQUOTES)
		token->key = TKN_WORD;

}

void	expand(t_data *data)
{
	t_token	*token;
	char	*key;
	char	*value;

	token = data->token_list;
	while (token)
	{
		if (token->key == TKN_WORD || token->key == TKN_DQUOTES)
		{
			if (token->key == TKN_DQUOTES)
				token->content++;
			key = envp_key(token->content);
			value = get_env_value(data, token->content);
		}
		if (value && key)
		{
			change_token_value(data, key, value);
		}
		token = token->next;
	}
	
}
