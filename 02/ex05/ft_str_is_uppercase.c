/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_str_is_uppercase.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/31 14:20:28 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/31 15:44:57 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	upper;
	int	c;

	upper = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'A' && str[c] <= 'Z')
			c++;
		else
		{
			upper = 0;
			c++;
		}
	}
	if (upper == 1 || str[0] == '\0')
		return (1);
	else
		return (0);
}
