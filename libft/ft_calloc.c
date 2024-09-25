/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:20:37 by peep              #+#    #+#             */
/*   Updated: 2024/09/25 15:22:10 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void *ft_calloc(size_t num, size_t size) {
    size_t total_size;
    void *ptr;
    unsigned char *p;
    size_t i;

    total_size = num * size;
    malloc(total_size);
    p = (unsigned char *)ptr;
    i = 0;
    if (ptr == NULL)
        return NULL;
    while (i < total_size)
    {
        p[i] = 0;
        i++;
    }
    return ptr;
}