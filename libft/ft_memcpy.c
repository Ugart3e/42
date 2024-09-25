/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:22:52 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:22:53 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memcpy(void *destination, const void *source, int num)
{
    unsigned char   *dest;
    unsigned char   *src;

    if (!dest || !src)
        return (0);
    dest = (unsigned char *)destination;
    src = (unsigned char *)source;
    while (0 < num--)
        *(dest++) = *(src++);
    return ((void *)destination);
}