/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_str_is_alpha.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/30 22:25:46 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/30 23:27:25 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	alfabetic;
	int	c;

	alfabetic = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'A' && str[c] <= 'Z')
			c++;
		else if (str[c] >= 'a' && str[c] <= 'z')
			c++;
		else
		{
			alfabetic = 0;
			c++;
		}
	}
	if (alfabetic == 1 || str[0] == '\0')
		return (1);
	else
		return (0);
}
