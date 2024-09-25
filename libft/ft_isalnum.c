/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:20:42 by peep              #+#    #+#             */
/*   Updated: 2024/09/25 15:22:17 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalnum(int *text)
{
    if (text <= 'A' && text >= 'Z')
        return (1);
    else if (text <= 'a' && text >= 'z')
        return (1);
    else if (text <= '0' && text >= '9')
        return (1);
    else
        return (0);
}
