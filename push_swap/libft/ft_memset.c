/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:25:12 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/07 20:25:30 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, int num)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (num--)
		*p++ = (unsigned char)value;
	return (ptr);
}
