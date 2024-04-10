#include "minishell.h"

//Crea el nodo cmd para despues este nodo pasarselo a otra funcion que
//crea el string del comando en si
void new_cmd_if(t_cmd **cmd_lst,t_cmd **new, int key)
{
	if (!*new || (new && (*new)->comand[0] && !(key == TKN_REDIR_APPEND || 
											key == TKN_REDIR_OUT ||
											key ==TKN_PIPE)))
	{
		*new = new_cmd();
		add_cmd_back(cmd_lst,*new);
	}
}

void add_word_cmd(t_cmd **new, t_token **token)
{
	while(*token && (*token)->key == TKN_WORD)
	{
		(*new)->command = 
	}
}

//VER SI EN LA MISTA NEW CMD PUEDO LLAMAR A LA FUNCION QUE ME CREE TAMBIEN
//EL STRING DE LA CMD

//comand to string

void    cmd_create(t_data *data)
{
    t_cmd   *new;
    t_token *token;
    int		fd_in;
	int		status;

	new = NULL;	
	fd_in = 0;
	token = data->token_list;
	status = unexpected_token(token);
	while (token && !status)
	{
		new_cmd_if(&data->cmd_list,&new,token->key);
		// add_word_cmd(t_cmd **new, t_token **token);
	}
	
}