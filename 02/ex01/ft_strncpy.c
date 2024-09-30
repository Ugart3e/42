/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/30 19:32:43 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/31 19:04:01 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	contador;
	int				encontrado;

	contador = 0;
	encontrado = 0;
	while (contador < n)
	{
		if (src[contador] == '\0')
		{
			encontrado = 1;
		}
		if (encontrado == 0)
		{
			dest[contador] = src[contador];
		}
		else
		{
			dest[contador] = '\0';
		}
		contador++;
	}
	return (dest);
}
