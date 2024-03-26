
#include "minishell.h"

//para sacar del input si hay algo seguido de un dolar
char	*envp_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\'')
		i++;
	return (ft_strndup(str, i));
}

char	*envp_value(t_data *data, char *str)
{
	t_env_list *env;
	char *key;
	
	key = envp_key(str);
	env = data->envp_list;
	while (env)
	{
		if (env->key && ft_strncmp(env->key, key, ft_strlen(key)))
			return (env->value);
		env = env->next;
	}
	if (!env)
		return (NULL);
	free(key);
	return(env->value);
}

int	valid_key(char c)
{
	if (ft_isalpha(c) || c == '?' || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}