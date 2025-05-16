/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsignedint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:45:52 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/11 15:46:08 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
