/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:22:57 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:22:58 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memmove(void *dest, const void *src, int numBytes)
{
    unsigned int    i;
    char*   d; 
    char*   s;

    i = 0;
    d = (char*)dest;
    s = (char*)src;
    if (s >= d)
    {
        while (i <= numBytes)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        while (i < numBytes)
        {
            d[i] = s[i];
            i++;
        }
    }
}