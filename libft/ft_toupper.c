/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:40:30 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/09 19:40:52 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int src)
{
	if (src >= 'a' && src <= 'z')
		return (src - 32);
	return (src);
}
