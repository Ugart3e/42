/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:36:44 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:54:36 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char    *ft_substr(char const *s, unsigned int start, size_t len) 
{
    char    *substr;
    size_t  i;
    size_t  s_len;
    
    if (!s)
        return NULL;
    s_len = 0;
    while (s[s_len] != '\0')
        s_len++;
    if (start >= s_len)
    {
        substr = (char *)malloc(1);
        if (substr)
            substr[0] = '\0';
        return substr;
    }
    if (len > s_len - start)
        len = s_len - start;
    substr = (char *)malloc(len + 1);
    if (!substr)
        return NULL;
    i = 0;
    while (i < len && s[start + i] != '\0') 
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return substr;
}