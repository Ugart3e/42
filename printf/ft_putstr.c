/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:47:39 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/19 14:59:29 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen( const char *str);

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}
