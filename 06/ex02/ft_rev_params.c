/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_rev_params.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/13 16:50:33 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/08/13 23:31:50 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 0)
		return (0);
	else
	{
		i = argc - 1;
		while (i != 0)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
