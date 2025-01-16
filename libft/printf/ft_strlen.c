/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:48:07 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/11 15:48:28 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen( const char *str)
{
	size_t	size;

	size = 0;
	while (str && str[size])
	{
		++size;
	}
	return (size);
}
