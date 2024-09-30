/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_str_is_numeric.c								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/31 13:32:38 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/31 13:38:41 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	numeric;
	int	c;

	numeric = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= '0' && str[c] <= '9')
			c++;
		else
		{
			numeric = 0;
			c++;
		}
	}
	if (numeric == 1 || str[0] == '\0')
		return (1);
	else
		return (0);
}
