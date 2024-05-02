
#include "minishell.h"

//para sacar del input si hay algo seguido de un dolar
char	*envp_key(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(*str))
		return (ft_strndup(str, i));
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\''
		&& str[i] != '\"')
		i++;
	return (ft_strndup(str, i));
}

char	*envp_value(t_data *data, char *str)
{
	t_env_list	*env;
	char		*key;

	key = envp_key(str);
	env = data->envp_list;
	while (env)
	{
		if (env->key && !ft_strncmp(env->key, key, ft_strlen(env->key)))
			break ;
		env = env->next;
	}
	if (!env)
		return (NULL);
	free(key);
	return (ft_strndup(env->value, ft_strlen(env->value)));
}

int	valid_key(char c)
{
	if (ft_isalpha(c) || c == '?' || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}


void append_env_value(char *str, const char *value, int *current)
{
	int len;

	len = ft_strlen(value);
	ft_memcpy(str + (*current), value, len);
	(*current) += len;
}