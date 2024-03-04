/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:51:23 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/04 15:28:50 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int console_init()
{
    printf("Welcome to minishell\n");
    return(0);
}

void sigint_handler(int sig) {
    printf("\nCtrl + C recibido. Saliendo de la consola.\n");
    exit(EXIT_SUCCESS);
}

int main() {
    char* input;
    char *user;
    signal(SIGINT, sigint_handler); 
    user = ft_strjoin(getenv("USER"),"$ ");
    // Bucle principal para leer y procesar entradas del usuario
    while (1) {
        input = readline(user); // Mostrar un prompt para el usuario
        if (!input) { // Comprobar si el usuario ha terminado de ingresar la entrada
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