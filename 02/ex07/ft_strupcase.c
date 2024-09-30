/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strupcase.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/31 15:56:01 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/31 16:05:26 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 97 && str[c] <= 122)
		{
			str[c] = (str[c] - 32);
		}
		c++;
	}
	return (str);
}
