/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:45:29 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/10 12:30:44 by pjimenez         ###   ########.fr       */
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

//****** CONSOLE INIT*****/
//console_init.c
void					console_init(t_data *data);

//*****SIGNALS HANDLER*****/
//signals_handler.c
void					signals_call(void);

//*******TOKEN FILL*********/
//token_init.c
void					fill_token(t_data *data, int key, char *value);
int						token_maker(t_data *data, char *str);

/*UTILS FOR THE PARSER*/

//parser_utils.c
int						special_chars(char c);
int						is_space(char c);

/******CHARACTER HANDLERS(TOKENIZER)*****/
//handlers.c
void					space_handler(t_data *data, char **str);
void					word_handler(t_data *data, char **str);
void					redir_handler(t_data *data, char **str);
void					quotes_handler(t_data *data, char **str);

/****EXPANSION CORE*******/
char					*envp_key(char *str);
char					*envp_value(t_data *data, char *str);
char					*get_env_value(t_data *data, char **input);
int						get_new_len(t_data *data, char *str);
int						valid_key(char c);
void					expand(t_data *data, char *input);

/****CMD FILL CORE*******/
t_cmd   *new_cmd();
void add_cmd_back(t_cmd **cmd,t_cmd *new_cmd);
int	unexpected_token(t_token *token);


/********FUNCION TEMPORAL print_token*******/
void					print_token(t_data *data);

/****FREE LISTS****/
void					free_token(t_token **token);

#endif