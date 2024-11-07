/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:15:16 by jougarte          #+#    #+#             */
/*   Updated: 2024/11/07 20:04:57 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read malloc free
//return linea leida o null
#include <stdio.h>
#include "get_next_line.h"

char	*ft_newline(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
	{
		i++;
	}
	return (ft_substr(line, 0, i));
}

char	*get_next_line(int fd)
{
	//static char	*save;
	char		*line;
	char		*pre;
	
	line = malloc (BUFFER_SIZE + 1);
	read(fd, line, BUFFER_SIZE);
	if (ft_strchr(line, '\n') != 0)
	{
		pre = ft_newline(line);
		line = malloc(ft_strlen(pre));
		line = pre;
	}
	
	return (line);
	
}

int main ()
{
	int fd = open("txt.txt", O_RDONLY);
	//r = linea 
		char *r = get_next_line(fd);
		printf("%s", r);
			return (0);

}