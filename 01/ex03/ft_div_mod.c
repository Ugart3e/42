/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_div_mod.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/29 21:41:51 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/07/29 21:43:54 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
