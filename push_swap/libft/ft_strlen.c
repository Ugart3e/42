/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:41:49 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/09 18:42:19 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *text)
{
	size_t	cnt;

	cnt = 0;
	while (text[cnt] != '\0')
		cnt++;
	return (cnt);
}
