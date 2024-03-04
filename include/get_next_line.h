/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:40:20 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/16 19:40:22 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

/**
 * @brief Function that read the first line of a file
 * 
 * @param fd File descriptor
 * @return char* Linea leida
 */
char	*get_next_line(int fd);
/**
 * @brief Function that creates a line
 * 
 * @param stack Stack of char
 * @return char* line created
 */
char	*ft_create_line(char *stack);
/**
 * @brief Function that updates the stack
 * 
 * @param stack Stack of char
 * @return char* Stack updated
 */
char	*update_stack(char *stack);
/**
 * @brief Function that returns the length of a string
 * 
 * @param fd File descriptor
 * @return char* Readed line
 */
size_t	ft_strlen_gnl(char *str);
/**
 * @brief Function that returns the position of a character
 * 
 * @param str String
 * @param c Sort by character
 * @return char* Char found
 */
char	*ft_strchr_gnl(const char *str, int c);
/**
 * @brief Function that copies a string
 * 
 * @param src String to copy
 * @return char* String copied
 */
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
