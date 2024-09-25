/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:23:12 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:23:13 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strdup(const char *s) {
    size_t len;
    char *dup;
    size_t i;

    len = 0;
    dup = (char *)malloc(len + 1);
    i = 0;
    while (s[len] != '\0') {
        len++;
    }
    if (dup == NULL) {
        return NULL;
    }
    while (i < len) {
        dup[i] = s[i];
        i++;
    }
    dup[len] = '\0';
    return dup;
}