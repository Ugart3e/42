/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:13:59 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/07 20:24:46 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	move_backward(char *d, const char *s, size_t *numBytes)
{
	while (*numBytes > 0)
	{
		(*numBytes)--;
		d[*numBytes] = s[*numBytes];
	}
}

static void	move_forward(char *d, const char *s, size_t numBytes)
{
	size_t	i;

	i = 0;
	while (i < numBytes)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t numBytes)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (d == s || numBytes == 0)
		return (dest);
	if (s < d)
		move_backward(d, s, &numBytes);
	else
		move_forward(d, s, numBytes);
	return (dest);
}
