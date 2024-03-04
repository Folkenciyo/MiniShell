
#include "minishell.h"

void sigint_handler(int sig) 
{
    printf("\nCtrl + C recibido. Saliendo de la consola.\n");
    exit(EXIT_SUCCESS);
}

int console_init() 
{
    char* input;
    char *user;
    signal(SIGINT, sigint_handler); 
    user = ft_strjoin(getenv("USER"),"$ ");
    // Bucle principal para leer y procesar entradas del usuario
    while (1) 
    {
        input = readline(user); // Mostrar un prompt para el usuario
        if (!input) 
        { // Comprobar si el usuario ha terminado de ingresar la entrada
            printf("\n");
            break;
        }
        if (strcmp(input,"clear") == 0)
            printf("\033[H\033[2J");    
        add_history(input); // Agregar la entrada a la historia para facilitar la navegación
        // Aquí puedes procesar la entrada del usuario como desees
        free(input); // Liberar la memoria asignada por readline
        rl_on_new_line();
    }
    return 0;
    
}