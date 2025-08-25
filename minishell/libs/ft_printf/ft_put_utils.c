/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:16:25 by anareval          #+#    #+#             */
/*   Updated: 2025/02/03 12:35:16 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	ft_putex(unsigned long long n)
{
	int					cont;
	unsigned long long	nb;

	cont = 1;
	nb = (unsigned long long) n;
	if (nb >= 16)
		cont += ft_putex(nb / 16);
	if (nb % 16 < 10)
		ft_putchar(nb % 16 + '0');
	else
		ft_putchar(nb % 16 + 87);
	return (cont);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	str;

	if (!ptr)
		return (ft_putstr("(nil)"));
	str = (unsigned long long) ptr;
	return (ft_putstr("0x") + ft_putex(str));
}

int	ft_putstr(char *s)
{
	int		cont;

	cont = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		cont ++;
	}
	return (cont);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
