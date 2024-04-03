
#include "minishell.h"

//handle ? == status del comando anterior
// get Key = a lo que hay en despues del dolar, sacamos eso
//y despues lo comparamos con la key de la lista y si coincide debvolvemos el value

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
			return ("");
		(*input) += ft_strlen(key);
	}
	free(key);
	return (value);
}

void	change_token_value(t_data *data, char *key, char *value)
{
	t_token	*token;

	token = data->token_list;
	while (token)
	{
		if (token->key == TKN_WORD || token->key == TKN_DQUOTES)
		{
			if (token->content && !ft_strncmp(token->content, key,
					ft_strlen(key)))
			{
				token->content = ft_strdup(value);
				token->len = ft_strlen(token->content);
			}
			if (token->key == TKN_DQUOTES || token->key == TKN_SQUOTES)
				token->key = TKN_WORD;
		}
		token = token->next;
	}
}

void	expand(t_data *data, char *input)
{
	char	*key;
	char	*value;

	value = NULL;
	key = NULL;
	while (*input)
	{
		if (*input == '$' && valid_key(*(input + 1)))
		{
			value = get_env_value(data, &input);
			key = envp_key((input + 1));
		}
		input++;
	}
	if (value && key)
		change_token_value(data, key, value);
}
