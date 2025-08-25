/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:07:40 by anareval          #+#    #+#             */
/*   Updated: 2025/05/05 16:58:28 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// Prints a formatted string to standard output (like printf).
int	ft_printf(char const *str, ...);

// Writes a character to standard output.
int	ft_putchar(char c);

// Writes a string to standard output.
int	ft_putstr(char *s);

// Writes an integer to standard output.
int	ft_putnbr(int n);

// Writes a pointer (memory address) in hexadecimal format.
int	ft_putptr(void *ptr);

// Writes a number in a specific base hexadecimal.
int	ft_putnbrex(int n, int i);

// Writes an unsigned number to standard output.
int	ft_putnbruns(int n);

#endif
