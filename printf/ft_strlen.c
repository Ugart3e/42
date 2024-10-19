/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:48:07 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/19 14:59:47 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen( const char *str)
{
	int	size;

	size = 0;
	while (str && str[size])
	{
		++size;
	}
	return (size);
}
