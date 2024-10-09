/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:08:48 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/09 18:35:29 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *s, int c)
{
	char	character;

	character = (char)c;
	while (*s != character)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
