/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:30:55 by juguerre          #+#    #+#             */
/*   Updated: 2023/04/18 20:30:57 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Include libraries */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* Functions from <ctype.h> library */

/**
 * @brief Test for ASCII character.
 * 
 * @param c Character to test.
 * @return Non-zero if c is an ASCII character, else 0.
*/
int			ft_isascii(int c);
/**
 * @brief Test for Alphanumeric char.
 * @return Non-zero if c is an alphanumeric character, else 0.
 */
int			ft_isalnum(int c);
/**
 * @brief Test for alphabetic char.
 * @return Non-zero if c is an alphabetic character, else 0.
 */
int			ft_isalpha(int c);
/**
 * @brief Test for decimal-digit char.
 * @return Non-zero if c is a decimal-digit character, else 0.
 */
int			ft_isdigit(int c);
/**
 * @brief Test for printable char.
 * @return Non-zero if c is a printable character, else 0.
 */
int			ft_isprint(int c);
/**
 * @brief Upper to lower case char conversion.
 * @return If c is an uppercase letter, returns its lowercase equivalent.
 */
int			ft_tolower(int c);
/**
 * @brief Lower to upper case char conversion.
 * @return If c is a lowercase letter, returns its uppercase equivalent.
 */
int			ft_toupper(int c);

/* 
** Functions from <stblib.h> library 
*/

/**
 * @brief Convert ASCII string to integer.
 * @return The converted value.
 */
long int	ft_atoi(const char *nptr);
/**
 * @brief Memory allocator.
 * @return Pointer to allocated memory.
 */
void		*ft_calloc(size_t nitems, size_t size);

/* 
** Function from <string.h> library 
*/

/**
 * @brief Write zeroes to a byte in a string.
 * @return Pointer to the memory area s.
 */
void		*ft_bzero(void *str, size_t n);
/**
 * @brief Locate a byte to a byte in a string.
 * @return Pointer to the byte located, or NULL
 *  if no such byte exists within n bytes.
 */
void		*ft_memset(void *str, int c, size_t n);
/**
 * @brief Locate a byte in a string.
 */
void		*ft_memchr(const void *str, int c, size_t n);
/**
 * @brief Compare a byte string.
 * @return An integer less than, equal to,
 *  or greater than zero if the first n bytes 
 * of s1 is found, respectively, to be less than, to match,
 *  or be greater than the first n bytes of s2.
 */
int			ft_memcmp(const void *buffer1, const void *buffer2, size_t count);
/**
 * @brief Copy byte string.
 * @return Pointer to dest.
 */
void		*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief Copy memory free.
 * @return Pointer to dest.
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/* 
** Function from  <strings.h> library 
*/

/**
 * @brief Find length of a string.
 * @return The length of the string.
 */
size_t		ft_strlen(const char *str);
/**
 * @brief Locate char in string (first concurrence).
 * @return Pointer to the byte located, or NULL if
 *  no such byte exists within n bytes.
 */
char		*ft_strchr(const char *str, int c);
/**
 * @brief Locate char in string (last concurrence).
 * @return Pointer to the byte located, or NULL 
 * if no such byte exists within n bytes.
 */
char		*ft_strrchr(const char *str, int c);
/**
 * @brief locate a substring in a string (size-bounded).
 * @return Pointer to the byte located, or NULL 
 * if no such byte exists within n bytes.
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t slen);
/**
 * @brief Save a copy of a string (with malloc).
 * @return Pointer to the copy.
 */
char		*ft_strdup(const char *str);
/**
 * @brief Save a copy of n characters of a string.
 * @return Pointer to the copy.
 */
char		*ft_strndup(const char *str, int n);
/**
 * @brief Size-Bounded string copying.
 * @return The length of the string.
 */
size_t		ft_strlcpy(char *dest, char *src, size_t size);
/**
 * @brief Sice-Bounded string concatenation.
 * @return The length of the string.
 */
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
/**
 * @brief Sice-Bounded  string cocomparation.
 * @return The length of the string.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* 
** Non Standart Functions 
*/

/**
 * @brief Output a char to given file.
 */
void		ft_putchar_fd(char c, int fd);
/**
 * @brief output a string to given file.
 */
void		ft_putstr_fd(char *str, int fd);
/**
 * @brief Output to given file with new-line.
 */
void		ft_putendl_fd(char *s, int fd);
/**
 * @brief Output integer to given file.
 */
void		ft_putnbr_fd(int nb, int fd);
/**
 * @brief Convert integer to ASCII string.
 * @return Pointer to the string.
 */
char		*ft_itoa(int n);
/**
 * @brief Extract substring from string.
 * @return Pointer to the substring.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief Trim started and ended string with the specified char.
 * @return Pointer to the substring.
 */
char		*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Concatenate two string  into a new string . (with malloc)
 * @return Pointer to the new string.
 */
char		*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Split string with specified char 
 * as delimiter. (given an array of strings).
 * @return Pointer to the array of strings.
 */
char		**ft_split(char const *s, char c);
/**
 * @brief Create a new string from modifying string with specified function.
 * @return Pointer to the new string.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Aplies a Function to each char of a string given.
 * @return Pointer to the new string.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* 
** PART 2 BONUS 
*/

/**
 * @brief Structure of a List.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Structure of a token.
*/
typedef struct s_token
{
	int				key;
	char			*content;
	int				len;
	struct s_token	*next;
}	t_token;

/* 
** List functions 
*/

/**
 * @brief Create a new List.
 * @return Pointer to the new List.
 */
t_list		*ft_lstnew(void *content);
/**
 * @brief Count elements of a List.
 * @return Number of elements.
 */
int			ft_lstsize(t_list *lst);
/**
 * @brief Find last element of a list.
 * @return Pointer to the last element.
 */
t_list		*ft_lstlast(t_list *lst);
/**
 * @brief Add new element at the end of a list.
 * @return Pointer to the last element.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Add new element at the begining of a list.
 * @return Pointer to the last element.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Delete element from a list.
 * @return Pointer to the last element.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void*));
/**
 * @brief Delete sequence of elements of a list from a starting point.
 * @return Pointer to the last element.
 */
void		ft_lstclear(t_list **lst, void (*del)(void*));
/**
 * @brief Aplay functions to content of all list´s elements.
 * @return Pointer to the last element.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Aplay functions to content of all list´s elements into a new list.
 * @return Pointer to the last element.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));


/*Token functions, literaly the same functions of lst but with tokens*/
t_token	*ft_tokennew(int key, char *content);
void	ft_tokenadd_back(t_token **lst, t_token *new);
void	ft_tokenadd_front(t_token **lst, t_token *new);


#endif
