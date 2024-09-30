/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_comb.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/25 16:38:17 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/25 17:43:26 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	imprimir_numeros(int n1, int n2, int n3)
{
	if (n1 != n2 && n2 != n3 && n1 != n3)
	{
		write(1, &n1, 1);
		write(1, &n2, 1);
		write(1, &n3, 1);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = 47;
	while (num1 <= 57)
	{
		num2 = num1 + 1;
		num1++;
		while (num2 <= 57)
		{
			num3 = num2 + 1;
			num2++;
			while (num3 <= 57)
			{
				imprimir_numeros(num1, num2, num3);
				num3++;
			}
		}
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
