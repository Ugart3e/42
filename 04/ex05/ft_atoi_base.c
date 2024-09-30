/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi_base.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/07 16:29:41 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/08/12 16:33:38 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	ft_isvalid(char c, int base)
{
	char	digits[17];
	char	digits2[17];
	int		ct;

	ct = 0;
	while (ct < 16)
	{
		if (ct <= 9)
		{
			digits[ct] = ct + '0';
			digits2[ct] = ct + '0';
		}
		else
		{
			digits[ct] = ct - 10 + 'a';
			digits2[ct] = ct - 10 + 'A';
		}
		ct++;
	}
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int	ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	else
		sign = 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}
