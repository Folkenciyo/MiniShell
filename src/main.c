/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:15:14 by pjimenez          #+#    #+#             */
/*   Updated: 2024/03/04 15:05:48 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>


size_t ft_strlen(char const *c)
{
    size_t i;

    i = 0;
    
    while (c[i])
    {
        i++;
    }
    return (i);
    
    
}



char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*cpy;
	size_t		i;
	size_t		full_len;

	i = 0;
	full_len = ft_strlen(s1) + ft_strlen(s2);
	cpy = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cpy)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		cpy[i] = s1[i];
		i++;
	}
	while (i < full_len)
	{
		cpy[i] = *s2++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
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