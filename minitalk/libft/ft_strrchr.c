/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:27:05 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/12 15:08:29 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	char		character;

	last = NULL;
	character = (char)c;
	while (*s)
	{
		if (*s == character)
			last = s;
		s++;
	}
	if (character == '\0')
		return ((char *)s);
	return ((char *)last);
}
