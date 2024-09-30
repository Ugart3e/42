/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/01 16:37:52 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/08/01 23:17:34 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	c2;
	unsigned int	c;

	c = 0;
	c2 = 0;
	while (dest[c] != '\0')
		c++;
	while (c2 < nb && src[c2] != '\0')
	{
		dest[c + c2] = src[c2];
		c2++;
	}
	dest[c + c2] = '\0';
	return (dest);
}

/*
int	 main(void)
{
		 char dest[50] = "Hola, ";
		 char src[] = "mundo";
		 ft_strncat(dest, src, 7);
		 printf("%s\n",dest);
	 return (0);
}*/
