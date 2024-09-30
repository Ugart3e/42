/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlen.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/04 20:49:11 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/08/04 20:58:35 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "Hola me llamo pepe";
	int n = ft_strlen(str);
	printf("%d",n);
	return 0;
}*/
