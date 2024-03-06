
#include "minishell.h"

// void sigint_handler(int sig) 
// {
//     printf("\nCtrl + C recibido. Saliendo de la consola.\n");
//     exit(EXIT_SUCCESS);
// }

void console_init() 
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
            printf("\n");
            break;
        }
        add_history(input);
        free(input);
        rl_on_new_line();
    }

}