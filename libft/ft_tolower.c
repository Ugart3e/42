/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:24:01 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:26:07 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char ft_tolower  (char *src)
{
    char    character;
    
    character = ' ';
    if (src >= 'A' && src <= 'Z')
        character = (src + 32);
    else
        character = src;
    return (character);
}