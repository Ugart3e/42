/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:26:14 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:26:15 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char ft_toupper  (char *src)
{
    char    character;

    character = ' ';
    if (src >= 'a' && src <= 'z')
        character = (src - 32);
    else
        character = src;
    return (character);
}