/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:52:52 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/11 22:52:58 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Include libraries */
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

/* 
** Main Functions 
*/

/**
 * @brief Print a formatted string to the standard output.
 * 
 * @param format The string to be printed.
 * @param ... The arguments to be printed.
 * @return int The number of characters printed.
 */
int		ft_printf(const char *format, ...);

/**
 * @brief Print a formatted string to the standard output.
 * 
 * @param format The string to be printed.
 * @param args The arguments to be printed.
 * @return int The number of characters printed.
 */
int		ft_formats(va_list args, const char format);

/* 
** Printer Functions 
*/

/**
 * @brief Print a character.
 * 
 * @param str The character to be printed.
 * @return int The number of characters printed.
 */
int		ft_printstr(char *str);
/**
 * @brief Print a character.
 * 
 * @param ptr The pointer to be printed.
 * @return int The number of characters printed.
 */
int		ft_printptr(unsigned long long ptr);
/**
 * @brief Print a pointer.
 * 
 * @param num The pointer to be printed.
 * @return int The number of characters printed.
 */
void	ft_putptr(uintptr_t num);
/**
 * @brief Print a unsigned int.
 * 
 * @param n The unsigned int to be printed.
 * @return int The number of characters printed.
 */
int		ft_printui(unsigned int n);
/**
 * @brief Print a number.
 * 
 * @param n The number to be printed.
 * @return int The number of characters printed.
 */
int		ft_printnbr(int n);
/**
 * @brief Print a unsigned int number.
 * 
 * @param n The unsigned int number to be printed.
 * @return int The number of characters printed.
 */
char	*ft_uitoa(unsigned int n);
/**
 * @brief Print a hexadecimal number.
 * 
 * @param num The hexadecimal number to be printed.
 * @param format The format of the hexadecimal number.
 * @return int The number of characters printed.
 */
int		ft_printhex(unsigned int num, const char format);
/**
 * @brief Print a hexadecimal number.
 * 
 * @param num The hexadecimal number to be printed.
 * @param format The format of the hexadecimal number.
 * @return int The number of characters printed.
 */
void	ft_puthex(unsigned int num, const char format);

/* Measurer Functions */

/**
 * @brief Measure the length of a string.
 * 
 * @param str The string to be measured.
 * @return int The length of the string.
 */
int		ft_ptrlen(uintptr_t num);
/**
 * @brief Measure the length of a number.
 * 
 * @param num The number to be measured.
 * @return int The length of the string.
 */
int		ft_numlen(unsigned	int num);
/**
 * @brief Measure the length of a hexadecimal number.
 * 
 * @param num The hexadecimal number to be measured.
 * @return int The length of the string.
 */
int		ft_hexlen(unsigned	int num);

#endif
