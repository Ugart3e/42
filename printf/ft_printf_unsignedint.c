/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsignedint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:45:52 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/21 15:48:41 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsignedint(unsigned int num)
{
	int	n;

	n = 0;
	if (num > 9)
	{
		n += ft_printf_unsignedint(num / 10);
	}
	return (n += ft_putchar(num % 10 + '0'));
}
