/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:02 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/07 20:10:22 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	int_len(long nbr);
static char	*pre_conv(int len);

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*result;

	nbr = n;
	len = int_len(nbr);
	*result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr == 0)
		return (handle_zero(result));
	if (n < 0)
	{
		nbr = -nbr;
		result[0] = '-';
	}
	fill_result(result, nbr, len);
	return (result);
}

static char	*handle_zero(char *result)
{
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static void	fill_result(char *result, long nbr, int len)
{
	int	i;

	i = len - 1;
	while (nbr != 0)
	{
		result[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	result[len] = '\0';
}

static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	return (tmp);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
