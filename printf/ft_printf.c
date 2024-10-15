/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:08:41 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/15 18:35:08 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_see_format(char character, va_list *args)
{
	int	cnt;

	if (character == 'c' || character == '%')
		return (ft_putchar(va_arg(*args, int)));
	else if (character == 'u')
		return (cnt);
	else if (character == 's')
		return (cnt);
	else if (character == 'x' || character == 'X')
		return (cnt);
	else if (character == 'd' || character == 'i')
		return (cnt);
	else if (character == 'p')
		return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	cnt;
	int				i;
	int				type;

	cnt = 0;
	i = 0;
	type = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			cnt += ft_see_format(format[i + 1], &args);
		else
		{
			ft_putchar(format[i]);
			cnt++;
		}
		i++;
	}
	va_end(args);
	return (cnt);
}

/* int main()
{
	ft_printf("Hola soy %s blablabla", "pepe");
	return 0;
} */