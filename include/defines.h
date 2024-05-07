/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:41:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/12 17:41:39 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* EXIT & ERROR MANAGE */
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define WRONG_ARG 2
# define MALLOC_ERROR 3
# define COMMAND_NULL 4
# define EXEC_ERROR "Unable to execute"

/* FILE DESCRIPTORS */
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define NO_FD -2

/* UNABLE */
# define FORK_ERROR "Unable to fork"
# define REDIR_ERROR "Unable to redirect"
# define EXEC_ERROR "Unable to execute"

/* BOOLEAN */
# define TRUE 1
# define FALSE 0

/*KEYS OF TOKENS*/
# define TKN_PIPE 1 // |
# define TKN_SQUOTES 2 //  ''
# define TKN_DQUOTES 3 // ""
# define TKN_REDIR_OUT 4 // >
# define TKN_REDIR_IN 5 // <
# define TKN_REDIR_APPEND 6 // >>
# define TKN_REDIR_SOURCE 7 // << here_doc
# define TKN_WORD 8 // word
# define TKN_SP 9 // any type of space
# define TKN_AFTER_REDIR 10 // \n

/* PATH*/
# define PATH_SIZE 4097

#endif