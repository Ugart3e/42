/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:08:41 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/14 19:20:20 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void ft_printf(const char *format, ...) {
	va_list			args;
	unsigned int	cnt;

	cnt = 0;
	va_start(args, format);
	
	//%c caracter
	//%s string
	//%p void * impreso en hexadecimal
	//%d numero decimal
	//%i numero entero
	//%u numero decimal sin signo
	//%x numero hexadecimal en minuscula
	//%X numero hexadecimal en mayuscula
	//%% simbolo porcentaje
	va_end(args);
}

int main()
{
	ft_printf("%s", "Hola soy Pepe");
	return 0;
}