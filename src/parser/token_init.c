#include "minishell.h"

void    fill_token(t_data data, int key, char *value)
{
    t_token	token;

	token = ft_tokennew(key, content);
    if (!data->token_list)
        ft_tokenadd_front(&data->token_list,token);
    else
        ft_tokenadd_back(&data->token_list,token);
}

int token_maker(t_data data,char *str)
{
    char    *tmp;

    tmp = str;

    while(*tmp)
    {
        /*
            if spacios
                tokenizer(espacios)
            if redir_in

            if redir_out

            if redir in

            if quotes

            if pipe
        */
    }
}