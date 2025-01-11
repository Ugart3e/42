/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:39:09 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/09 18:40:11 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	c1;
	size_t	c2;
	size_t	i;

	c1 = 0;
	c2 = 0;
	i = 0;
	while (dest[c1] != '\0')
		c1++;
	while (src[c2] != '\0')
		c2++;
	if (size <= c1)
		return (size + c2);
	while (src[i] != '\0' && (c1 + i) < (size - 1))
	{
		dest[c1 + i] = src[i];
		i++;
	}
	dest[c1 + i] = '\0';
	return (c1 + c2);
}

/*
#include <stdio.h>
int main(void)
{
    char str[] = "Worldiouasd";
    size_t siz = 2;
    char dest[50] = "Hello ";
    size_t tot;

    tot = ft_strlcat(dest, str, siz);
    printf("%s\n", dest);
    printf("%zu\n", tot); // Usa %zu para imprimir size_t
}
*/
