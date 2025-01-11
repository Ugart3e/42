/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:37:26 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/21 12:56:40 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formatter(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_printf_ptr(va_arg(*args, uintptr_t)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_printf_unsignedint(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_printf_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_printf_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		length;
	int		sum;

	va_start(args, format);
	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			sum = formatter(format[i + 1], &args);
			i++;
		}
		else
			sum = ft_putchar(format[i]);
		if (sum == -1)
			return (-1);
		else
			length += sum;
		i++;
	}
	va_end(args);
	return (length);
}
