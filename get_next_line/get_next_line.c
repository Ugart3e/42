/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:15:16 by jougarte          #+#    #+#             */
/*   Updated: 2024/11/07 16:46:06 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read malloc free
//return linea leida o null
#include <stdio.h>
#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	static char	*line;
	
	line = malloc (BUFFER_SIZE + 1);
	read(fd, line, BUFFER_SIZE);
	return line;
	
}

int main ()
{
	int fd = open("txt.txt", O_RDONLY);
	//r = linea 
	for (size_t i = 0; i < 10; i++)
	{
		char *r = ft_get_next_line(fd);
		printf("%s", r);

	}
			return (0);

}