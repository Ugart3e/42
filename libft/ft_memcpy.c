/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:11:37 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/07 20:13:53 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char			*dest;
	const unsigned char		*src;

	*dest = (unsigned char *)destination;
	*src = (const unsigned char *)source;
	if (!dest && !src)
		return (NULL);
	while (num-- > 0)
		*dest++ = *src++;
	return (destination);
}
