#include "minishell.h"

void    fill_token(t_data *data, int key, char *value)
{
    t_token	*token;

	token = ft_tokennew(key, value);
  
    if (!data->token_list)
        ft_tokenadd_front(&data->token_list,token);
    else
        ft_tokenadd_back(&data->token_list,token);
}

int token_maker(t_data *data,char *str)
{
    char    *tmp;

    tmp = str;

    while(*tmp)
    {
        
        if (is_space(*tmp))
            space_handler(data,&tmp); 
        else if (!special_chars(*tmp))
            word_handler(data,&tmp);
        else if (*tmp == '>' || *tmp == '<')
            redir_handler(data,&tmp);
        /*
            if redir_out

            if redir in

            if quotes

            if pipe
        */
       tmp++;
    }
    while (data->token_list)
    {
        
        printf("key : %d\n",data->token_list->key);
        printf("content : %s\n",data->token_list->content);
        printf("len : %d\n",data->token_list->len);
        printf("--------------------------------------------\n");
        data->token_list = data->token_list->next;
    }
    
    return (1);
}