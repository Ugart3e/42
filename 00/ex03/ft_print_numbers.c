/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_numbers.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/25 13:06:40 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/25 13:39:21 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int			number;
	char		c;

	number = 0;
	while (number <= 9)
	{
		c = number + '0';
		write (1, &c, 1);
		number++ ;
	}
}
