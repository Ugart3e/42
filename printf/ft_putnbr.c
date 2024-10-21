/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:47:12 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/21 12:42:07 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
