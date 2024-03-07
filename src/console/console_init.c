
#include "minishell.h"

// void sigint_handler(int sig) 
// {
//     printf("\nCtrl + C recibido. Saliendo de la consola.\n");
//     exit(EXIT_SUCCESS);
// }

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
        //tokenizer(data,input);
        if (*input != '\0')
			add_history(input);
        free(input);
        rl_on_new_line();
    }
    clear_history();

}