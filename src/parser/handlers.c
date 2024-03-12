#include "minishell.h"

//SIN APLICAR HASTA NUEVO AVISO
void space_handler(t_data *data, char **str)
{
    char	*tmp;
    char    *start;

    start = *str;
    while (is_space(*(*str + 1)))
    {
        (*str)++;
    }
	tmp = ft_strndup(start,*str + 1 - start);
	fill_token(data,TKN_SP,tmp);
	free(tmp);
    
}

void word_handler(t_data *data, char **str)
{
   
    char	*start;
    char    *tmp;

	tmp = NULL;
	if (!special_chars(**str)
		|| (*(*str + 1) && **str == '&' && *(*str + 1) != '&'))
	{
		start = *str;
		while (*(*str + 1) && (!special_chars(*(*str + 1)) || (**str == '&'
					&& *(*str + 1) != '&')))
			(*str)++;
		tmp = ft_strndup(start, *str + 1 - start);
        printf("tmp :%s\n",tmp);
		fill_token(data, TKN_WORD, tmp);
	}
    free(tmp);
}

void redir_handler(t_data *data,char **str)
{

    if (**str == '>')
    {
        if (ft_strncmp(*str,">>",2) == 0)
        {
            fill_token(data,TKN_REDIR_APPEND,">>");
            (*str)++;
        }
        else
            fill_token(data,TKN_REDIR_OUT,">");

    }
    else if (**str == '<')
    {
        if (ft_strncmp(*str,"<<",2) == 0)
        {
            fill_token(data,TKN_REDIR_SOURCE,"<<");
            (*str)++;
        }
        else
            fill_token(data,TKN_REDIR_IN,"<");
    }
    

}