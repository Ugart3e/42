/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:41:18 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/09 18:41:29 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	totalsize;
	size_t	cnt1;

	totalsize = 0;
	cnt1 = 0;
	while (src[totalsize] != '\0')
		totalsize++;
	if (size == 0)
		return (totalsize);
	while (cnt1 < size - 1 && src[cnt1] != '\0')
	{
		dest[cnt1] = src[cnt1];
		cnt1++;
	}
	dest[cnt1] = '\0';
	return (totalsize);
}

/*
#include <stdio.h>
int main(void)
{
    char src[] = "Hello, World!";
    char dest[50];
    size_t size = 5;

    size_t result = ft_strlcpy(dest, src, size);
    printf("Dest: %s\n", dest);
    printf("Total size: %zu\n", result);
}
*/