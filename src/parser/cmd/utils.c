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
		if (tmp->key == TKN_PIPE 
			|| tmp->key == TKN_REDIR_APPEND
			|| tmp->key == TKN_REDIR_IN
			|| tmp->key == TKN_REDIR_OUT
			|| tmp->key == TKN_REDIR_SOURCE
			&& (!tmp->next || (tmp->next && tmp->next != TKN_WORD)))
				return(269);
		tmp = tmp->next;
	}
	return(0);
}