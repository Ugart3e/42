/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:49:39 by jougarte          #+#    #+#             */
/*   Updated: 2024/08/01 16:35:59 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	c2;

	c = 0;
	c2 = 0;
	while (dest[c] != '\0')
	{
		c++;
	}
	while (src[c2] != '\0')
	{
		dest[c + c2] = src[c2];
		c2++;
	}
	dest[c + c2] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char dest[50] = "Hola, ";
	char src[] = "mundo";
	ft_strcat(dest, src);
	printf("%s\n",dest);
	return (0);
}*/
