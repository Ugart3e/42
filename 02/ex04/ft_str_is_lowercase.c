/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:14:36 by jougarte          #+#    #+#             */
/*   Updated: 2024/07/31 14:19:05 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	lower;
	int	c;

	lower = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'a' && str[c] <= 'z')
			c++;
		else
		{
			lower = 0;
			c++;
		}
	}
	if (lower == 1 || str[0] == '\0')
		return (1);
	else
		return (0);
}
