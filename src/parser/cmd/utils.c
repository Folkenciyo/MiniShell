#include "minishell.h"

//Basicamente una funcion para gestionar el error de unexpected token
int	unexpected_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	if (tmp && tmp->key == TKN_PIPE)
		return(256); //para que no salga por ninguna salida de error
	while (tmp->next)
	{
		if ((tmp->key == TKN_PIPE 
			|| tmp->key == TKN_REDIR_APPEND
			|| tmp->key == TKN_REDIR_IN
			|| tmp->key == TKN_REDIR_OUT
			|| tmp->key == TKN_REDIR_SOURCE
			)&& (!tmp->next || (tmp->next && tmp->next->key != TKN_WORD)))
				return(269);
		tmp = tmp->next;
	}
	return(0);
}

char	**add_to_array(char **arr, char *new_str)
{
	size_t	i;
	size_t	j;
	char	**new_arr;

	i = 0;
	j = 0;
	while (arr && arr[i])
		i++;
	new_arr = ft_calloc(i + 2, sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (j < i)
	{
		new_arr[j] = arr[j];
		j++;
	}
	new_arr[i] = new_str;
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}