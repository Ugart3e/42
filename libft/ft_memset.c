/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:23:03 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:23:04 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//1: turn ptr to byte, 2: Asign value to position, 3: return pointer
void    *ft_memset(void *ptr, int value, int num)
{
    unsigned char *p; 
    
    p = (unsigned char *)ptr;
    while (num--)
        *p++ = (unsigned char)value;
    return (ptr);
}
