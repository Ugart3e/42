/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_rev_int_tab.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/30 10:40:27 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/30 11:36:05 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}
