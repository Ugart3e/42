/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:55:12 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/14 12:16:40 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int text)
{
	if (text >= 'A' && text <= 'Z')
		return (1);
	else if (text >= 'a' && text <= 'z')
		return (1);
	else if (text >= '0' && text <= '9')
		return (1);
	else
		return (0);
}
