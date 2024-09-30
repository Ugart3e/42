/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jougarte <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/07 13:54:54 by jougarte		  #+#	#+#			 */
/*   Updated: 2024/08/12 16:33:01 by jougarte		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	s;
	int	r;

	s = 1;
	r = 0;
	while (*str > '9')
		break ;
	while (*str < 42)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = s * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	return (r * s);
}

/*
int main()
{
	printf("ft_atoi: %d\n", ft_atoi("123456"));
	printf("atoi: %d\n", atoi("123456"));
	printf("ft_atoi: %d\n", ft_atoi("12Three45678"));
	printf("atoi: %d\n", atoi("12Three45678"));
	printf("ft_atoi: %d\n", ft_atoi("Hello World!"));
	printf("atoi: %d\n", atoi("Hello World!"));
	printf("ft_atoi: %d\n", ft_atoi("+42 BLAH!"));
	printf("atoi: %d\n", atoi("+42 BLAH!"));
	printf("ft_atoi: %d\n", ft_atoi("-42"));
	printf("atoi: %d\n", atoi("-42"));
	printf("ft_atoi: %d\n", ft_atoi("	 +42"));
	printf("atoi: %d\n", atoi("	 +42"));
	printf("ft_atoi: %d\n", ft_atoi("\t\n\v\f\r 42"));
	printf("atoi: %d\n", atoi("\t\n\v\f\r 42"));
	printf("ft_atoi: %d\n", ft_atoi("5"));
	printf("atoi: %d\n", atoi("5"));
	printf("atoi: %d\n", atoi("-+--+-42"));
	return 0;
}*/
