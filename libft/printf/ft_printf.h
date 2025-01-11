/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:39:11 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/19 14:53:23 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(char const *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_strlen( const char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_printf_ptr(uintptr_t ptr);
int		ft_putnbr(int n);
int		ft_printf_unsignedint(unsigned int num);
int		ft_printf_hex(unsigned int nr, char *base);

#endif