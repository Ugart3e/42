/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:15:59 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/09 18:34:32 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*temp;
	size_t	cont;
	size_t	cont2;

	cont = 0;
	cont2 = 0;
	temp = (char *)s1;
	temp = (char *)malloc (((ft_strlen(s1) + ft_strlen(s2) + 1))
			* sizeof(char));
	if (!temp)
		return (NULL);
	while (cont < (ft_strlen(s1)))
		temp[cont2++] = s1[cont++];
	cont = 0;
	while (s2[cont])
	{
		temp[cont2] = s2[cont];
		cont2++;
		cont++;
	}
	temp[cont2] = '\0';
	return (temp);
}
