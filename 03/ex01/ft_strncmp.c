/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:13:32 by jougarte          #+#    #+#             */
/*   Updated: 2024/08/01 23:02:48 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (c < n && s1[c] != '\0' && s2[c] != '\0')
	{
		if (s1[c] != s2[c])
			return (s1[c] - s2[c]);
		c++;
	}
	if (c < n)
		return (s1[c] - s2[c]);
	return (0);
}

/*
int main(void)
{
	char str1[] = "Helloworld";
	char str2[] = "Hello";
	char str3[] = "Abuela";
	int res = 0;
	res = ft_strncmp(str1, str2, 7);
	printf("%d",res);
	return (0);
}*/
