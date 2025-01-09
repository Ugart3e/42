/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:31:35 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/09 19:40:12 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		cont;
	char		*temp;

	temp = (char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	temp = ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		temp[cont] = s[start + cont];
		cont++;
	}
	return ((char *)temp);
}
