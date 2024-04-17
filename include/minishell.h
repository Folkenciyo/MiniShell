/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:45:29 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/17 14:10:22 by juguerre         ###   ########.fr       */
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
// cd.c
int						cd(t_data *data, char **cmd);
void					ft_free_dirs(char *s1, char *s2, char *s3);
//cd_utils.c
int        	            ft_cd_home(t_data *data);
int        	            ft_cd_lastdir(t_data *data);
void					ft_update_pwds(t_data *data, char *current_dir, char *new_dir);
int						ft_cd_other(t_data *data, char *dir);
int						ft_cd_home_relat(t_data *data, char *dir);
//tuple_utils.c
int						ft_var_exists(char *variable, char *envp_tuple);
char					*ft_store_value(char *tuple);
char					*ft_get_env_value(t_data *data, char *key);
int						ft_var_size(char *tuple);
//tupla_utils2.c
int						ft_contains(char *envp_tuple, char *tuple);
int						ft_env_exists(char *tuple, char **envp);
//export.c
int						export(t_data *data, char **cmd);
int 				   ft_export(t_data *data, char *tuple);
//export_utils.c
void					ft_print_export(t_data *data);
char					**ft_order_env(char **envp);
void					ft_modify_variable(char **envp, char *tuple);
char					**ft_add_to_matrix(char **envp, char *tuple);
//export_utils2.c
int 					ft_empty_line(char *line);
int						ft_double_assign(char *line);
char					**ft_init_matrix_nil(int size);
int						ft_max_len(char *str1, char *str2);
int 					ft_not_in_matrix(char *str, char **matrix);
//env_utils.c
void					ft_free_matrix(char **matrix);
int						ft_matrix_size(char **matrix);
char					**ft_copy_matrix(char **envp);
int 					ft_init_envp(t_data *data, char **envp);
//refill_env_lst.c
void					ft_t_lstclear(t_env_list **envp_lst);
void					refill_envp_lst(t_data *data, char **new_envp);
//env
int						env(t_data *data, char **cmd);
//exit.c
int						ft_exit(t_data *data, int option);
int						exit1(t_data *data, char **cmd);
//unset.c
int						ft_unset(t_data *data, char *tuple);
int						unset(t_data *data, char **cmd);
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