/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:00:08 by anareval          #+#    #+#             */
/*   Updated: 2025/06/30 18:49:07 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_get_sign(const char *str, int *i)
{
	int	sig;

	sig = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sig = -1;
		(*i)++;
	}
	return (sig);
}

long long	ft_atoll(const char *str)
{
	long long	n;
	int			sig;
	int			i;

	i = 0;
	n = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	sig = ft_get_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sig == 1 && (n > LLONG_MAX / 10
				|| (n == LLONG_MAX / 10 && (str[i] - '0') > LLONG_MAX % 10)))
			return (LLONG_MAX);
		if (sig == -1 && (n > -(LLONG_MIN / 10)
				|| (n == -(LLONG_MIN / 10) && (str[i] - '0')
					> -(LLONG_MIN % 10))))
			return (LLONG_MIN);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sig);
}
