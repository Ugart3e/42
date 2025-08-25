/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:14:57 by anareval          #+#    #+#             */
/*   Updated: 2025/02/03 12:39:09 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		cont;

	cont = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		cont++;
	}
	if (nb >= 10)
		cont += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (cont);
}

int	ft_putnbrex(int n, int i)
{
	long	nb;
	int		cont;
	char	c;

	cont = 1;
	nb = (unsigned int)n;
	if (i == 1)
		c = 55;
	else
		c = 87;
	if (nb >= 16)
		cont += ft_putnbrex(nb / 16, i);
	if (nb % 16 < 10)
		ft_putchar(nb % 16 + '0');
	else
		ft_putchar(nb % 16 + c);
	return (cont);
}

int	ft_putnbruns(int n)
{
	long	nb;
	int		cont;

	cont = 1;
	nb = (unsigned int)n;
	if (nb >= 10)
		cont += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (cont);
}
