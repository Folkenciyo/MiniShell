#include "minishell.h"

void space_handler(t_data *data, char *str)
{
    int 	i;
    char	*tmp;
    i = 0;
    while (is_space(str[i]))
        i++;
	
	tmp = ft_strndup(str,i);
	fill_token(data,TKN_SP,tmp);
	free(tmp);
    
}