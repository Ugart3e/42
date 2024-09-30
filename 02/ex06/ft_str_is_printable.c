/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_str_is_printable.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/31 15:47:33 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/31 15:53:17 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	c;
	int	printable;

	c = 0;
	printable = 1;
	while (str[c] != '\0')
	{
		if (str[c] >= 32 && str[c] <= 126)
			c++;
		else
		{
			c++;
			printable = 0;
		}
	}
	if (printable == 1 || str[0] == '\0')
		return (1);
	else
		return (0);
}
