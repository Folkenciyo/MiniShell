
#include "minishell.h"

void console_init(t_data *data)
{
    char* input;
    char *user;
    user = ft_strjoin(getenv("USER"),"$ ");
    
    while (1) 
    {
        signals_call();
        input = readline(user);
        if (!input) 
        {
            printf("exit\n");
            data->exit = 1;
            break;
        }

        add_history(input);
        token_maker(data,input);
        if (*input != '\0')
			add_history(input);
        free(input);
        free_token(&data->token_list);
        rl_on_new_line();
    }
    free(user);
    clear_history();

}