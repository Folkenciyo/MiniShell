/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:45:29 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/23 12:42:11 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/**
 * @brief El "batch mode" (modo de lotes) es un término que se refiere a
 * un modo de operación en el que un programa ejecuta una secuencia de
 * comandos o tareas automáticamente, sin intervención directa del usuario.
 * En este modo, el programa lee una lista predefinida de comandos o
 * instrucciones desde un archivo o desde la entrada estándar,
 * ejecuta estas instrucciones en secuencia y luego finaliza.
 */
//int						g_batch_mode_flag;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_cmd
{
	char				**comand;
	char				**choosen_path;
	int					*fd_in;
	int					*fd_out;
	struct s_cmd		*next;
}						t_cmd;

typedef struct s_data
{
	char				*built_in_cmd[8];
	int					status;
	int					exit;
	char				**envp;
	t_env_list			*envp_list;
	t_token				*token_list;
	t_cmd				*cmd_list;
}						t_data;

/******** INIT DATA *********/
// init_data.c
int						init_data(t_data *data, char **envp);

/******** ENV LIST *********/
// envp_list_manage.c
t_env_list				*envp_list_new(char *key, char *value);
t_env_list				*envp_list_add_back(t_env_list *lst, t_env_list *new);
void					envp_list_add_front(t_env_list *lst, t_env_list *new);

/******** BUILD IN *********/

///////////////////////// cd.c /////////////////////////
/**
 * @brief Esta función verifica si el comando es "cd" y, si es así, 
 * llama a la función ft_cd	
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int						cd(t_data *data, char **cmd);
/**
 * @brief Implementa el comando cd:
 * Si no hay argumentos después de "cd", cambia al directorio home.
 * Si el primer argumento es "-", cambia al último directorio visitado.
 * Si el primer argumento es "~", cambia al directorio home.
 * Si el primer argumento es "..", cambia al directorio padre.
 * Si el primer argumento es ".", cambia al directorio actual.
 * Si el primer argumento es "/", cambia al directorio raíz.
 * Si el primer argumento es cualquier otra cosa, cambia a ese directorio
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int						ft_cd(t_data *data, char **cmd);
/**
 * @brief Libera la memoria asignada a las cadenas s1, s2 y s3
 * 
 * @param s1 
 * @param s2 
 * @param s3 
 */
void					ft_free_dirs(char *s1, char *s2, char *s3);

///////////////////////// cd_utils.c /////////////////////////
/**
 * @brief Cambia al directorio home
 * chdir() es una llamada al sistema en C que cambia el directorio 
 * de trabajo actual del proceso a la ruta especificada 
 * 
 * @param data 
 * @return int 
 */
int        	            ft_cd_home(t_data *data);
int        	            ft_cd_lastdir(t_data *data);
/**
 * @brief Actualiza las variables de entorno OLDPWD con el directorio actual
 * y PWD con el nuevo directorio
 * 
 * @param data 
 * @param current_dir 
 * @param new_dir 
 */
void					ft_update_pwds(t_data *data, char *current_dir, char *new_dir);
/**
 * @brief Cambia a un directorio especificado por el usuario
 * 
 * @param data 
 * @param dir 
 * @return int 
 */
int						ft_cd_other(t_data *data, char *dir);
/**
 * @brief Cambia a un directorio relativo al directorio home
 * 
 * @param data 
 * @param dir 
 * @return int 
 */
int						ft_cd_home_relat(t_data *data, char *dir);
/**
 * @brief Cambia al último directorio visitado
 * 
 * @param data 
 * @return int 
 */
int						ft_cd_lastdir(t_data *data);

///////////////////////// echo.c /////////////////////////
/**
 * @brief Implementa el comando echo:
 * Si no hay argumentos después de "echo", imprime una nueva línea.
 * Si hay argumentos después de "echo", imprime los argumentos.
 * Si hay argumentos después de "echo" y el primer argumento es "-n",
 * imprime los argumentos sin una nueva línea.
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int 				   ft_echo(char **cmd);

//////////////////////// pws.c /////////////////////////
/**
 * @brief Implementa el comando pwd:
 * Imprime el directorio de trabajo actual
 * 
 * @return int 
 */
int 					ft_pwd(void);
/**
 * @brief Verifica si el comando es "pwd" y, si es así, llama a la función ft_pwd
 * 
 * @param cmd 
 * @return int 
 */
int 					pwd(char **cmd);

////////////////////// tuple_utils.c ///////////////////////
/**
 * @brief Verifica si una variable de entorno existe en una tupla de entorno. 
Devuelve TRUE si la variable existe y FALSE en caso contrario.
 * 
 * @param variable 
 * @param envp_tuple 
 * @return int 
 */
int						ft_var_exists(char *variable, char *envp_tuple);
/**
 * @brief Almacena el valor de una variable de entorno en una cadena
 * 
 * @param tuple 
 * @return char* 
 */

char					*ft_store_value(char *tuple);
/**
 * @brief Obtiene el valor de una variable de entorno
 * 
 * @param data 
 * @param key 
 * @return char* 
 */
char					*ft_get_env_value(t_data *data, char *key);
/**
 * @brief Calcula el tamaño de una variable de entorno
 * 
 * @param tuple 
 * @return int 
 */
int						ft_var_size(char *tuple);
//////////////////////////// tupla_utils2.c ////////////////////////////
/**
 * @brief Verifica si 'tuple' está contenido en 'envp_tuple'
 * 
 * @param envp_tuple
 * @param tuple
 * @return int
*/
int						ft_contains(char *envp_tuple, char *tuple);
/**
 * @brief Verifica si 'tuple' está contenido en 'envp'
 * 
 * @param tuple
 * @param envp
 * @return int
*/
int						ft_env_exists(char *tuple, char **envp);

/////////////////////// export.c ///////////////////////
/**
 * @brief Imprime todas las variables de entorno
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int 					ft_print_error(char *cmd);
/**
 * @brief Implementa el comando export:
 * Si no hay argumentos después de "export", imprime todas las variables de entorno.
 * Si hay argumentos después de "export", añade las variables de entorno.
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int						export(t_data *data, char **cmd);
/**
 * @brief Imprime todas las variables de entorno
 * 
 * @param data 
 */
int 				  	ft_export(t_data *data, char *tuple);

////////////////////// export_utils.c ///////////////////////
/**
 * @brief Crea una cadena con el carácter de mayor valor en ASCII (127) para 
 * usarla como comparador en la búsqueda de la cadena más pequeña
 * 
 * @return char* 
 */
char					*ft_str_comparator(void);
/**
 * @brief Encuentra la cadena más pequeña en la matriz de cadenas envp
 * 
 * @param data 
 */
char					*ft_find_min_str(char **envp, char **new_envp);
/**
 * @brief Ordena la matriz de cadenas envp alfabéticamente
 * 
 * @param envp 
 * @return char** 
 */
char					**ft_order_env(char **envp);
/**
 * @brief Modifica una variable de entorno en la matriz de cadenas envp
 * con la nueva variable de entorno 'tuple'
 * 
 * @param envp 
 * @param tuple 
 */
void					ft_modify_variable(char **envp, char *tuple);
/**
 * @brief Añade 'tuple' a 'envp'
 * 
 * @param envp 
 * @param tuple 
 * @return char** 
 */
char					**ft_add_to_matrix(char **envp, char *tuple);

////////////////////// export_utils2.c ///////////////////////
/**
 * @brief Verifica si la cadena es una variable de entorno
 * 
 * @param line 
 * @return int 
 */
int 					ft_empty_line(char *line);
/**
 * @brief Verifica si la cadena tiene más de un signo "="
 * 
 * @param line 
 * @return int 
 */
int						ft_double_assign(char *line);
/**
 * @brief Inicializa una matriz de cadenas con todos sus elementos a NULL
 * 
 * @param size 
 * @return char** 
 */
char					**ft_init_matrix_nil(int size);
/**
 * @brief Encuentra la cadena más larga en la matriz de cadenas envp
 * 
 * @param envp 
 * @param new_envp 
 * @return char* 
 */
int						ft_max_len(char *str1, char *str2);
/**
 * @brief Verifica si una cadena 'string' no está en la matriz 
 * de cadenas 'envp'
 * 
 * @param envp 
 * @param new_envp 
 * @return char* 
 */
int 					ft_not_in_matrix(char *str, char **matrix);

////////////////////// env_utils.c ///////////////////////
/**
 * @brief Libera la memoria asignada a la matriz de cadenas envp
 * 
 * @param matrix 
 */
void					ft_free_matrix(char **matrix);
/**
 * @brief Calcula el tamaño de la matriz de cadenas envp
 * 
 * @param envp 
 * @return int 
 */
int						ft_matrix_size(char **matrix);
/**
 * @brief Copia la matriz de cadenas envp
 * 
 * @param envp 
 * @return char** 
 */

char					**ft_copy_matrix(char **envp);
/**
 * @brief Inicializa la matriz de cadenas envp
 * 
 * @param data 
 * @param envp 
 * @return int 
 */
int 					ft_init_envp(t_data *data, char **envp);

////////////////// refill_env_lst.c /////////////////////
/**
 * @brief Libera la memoria asignada a la lista de variables de entorno
 * 
 * @param envp_lst 
 */
void					ft_t_lstclear(t_env_list **envp_lst);
/**
 * @brief Actualiza la lista de variables de entorno con la nueva matriz de cadenas
 * 
 * @param data 
 * @param new_envp 
 */
void					refill_envp_lst(t_data *data, char **new_envp);

/////////////////////// env.c ///////////////////////////
/**
 * @brief Imprime las variables de entorno llamando a ft_env()
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int						env(t_data *data, char **cmd);

/////////////////////// exit.c ///////////////////////////
/**
 * @brief Implementa el comando exit:
 * Establece el estado de salida y cambia la flag de salida a 1
 * 
 * @param data
 * @param option
 * @return int
 */
int						ft_exit(t_data *data, int option);
/**
 * @brief Verifica si el comando es "exit" y, si es así, llama a
 *  la función ft_exit
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int						exit1(t_data *data, char **cmd);

/////////////////////// unset.c ///////////////////////////
/**
 * @brief Elimina una variable de entorno de la matriz de cadenas envp
 * 
 * @param data 
 * @param tuple 
 * @return int 
 */
int						ft_unset(t_data *data, char *tuple);
/**
 * @brief Verifica si el comando es "unset" y, si es así, llama a la función ft_unset
 * 
 * @param data 
 * @param cmd 
 * @return int 
 */
int						unset(t_data *data, char **cmd);
/**
 * @brief Elimina una variable de entorno de la matriz de cadenas envp
 * 
 * @param data 
 * @param tuple 
 */
void 					ft_delete_variable(t_data *data, char *tuple);

/******** PIPEX *********/
// pipex.c
int						ft_pipex(t_data *data);
int						ft_exec_cmd(t_data *data, t_cmd *list, int cmd_number);
//pipex_fd_builts_utils.c
int						ft_built_in(t_data *data, t_cmd *node);
void					ft_redir_fd_std(int fd, int std, int fd2);
int						ft_list_len(t_cmd *list);
int						ft_exec_builtin(t_data *data, char **cmd);
int						ft_cmd_is_built_in(t_data *data, char *str);
//pipex_utils.c
char					*abs_bin_path(char *cmd, char **envp);
char					**get_paths(char *envp[]);
int						ft_is_builtin(t_data *data, char *str);
char					*ft_valid_cmd(char *cmd);
int						ft_print_error(char *cmd);



//****** CONSOLE INIT*****/
//console_init.c
void					console_init(t_data *data);

//*****SIGNALS HANDLER*****/
//signals_handler.c
void					signals_call(void);

//*******TOKEN FILL*********/
//token_init.c
void    fill_token(t_data *data, int key, char *value);
int     token_maker(t_data *data,char *str);

/*UTILS FOR THE PARSER*/

//parser_utils.c
int						special_chars(char c);
int						is_space(char c);

/******CHARACTER HANDLERS(TOKENIZER)*****/
//handlers.c
void	space_handler(t_data *data, char **str);
void	word_handler(t_data *data, char **str);
void	redir_handler(t_data *data,char **str);
void	quotes_handler(t_data *data, char **str);

/********FUNCION TEMPORAL print_token*******/
void					print_token(t_data *data);

/****FREE LISTS****/
void					free_token(t_token **token);

#endif