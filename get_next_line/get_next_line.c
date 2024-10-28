/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:15:16 by jougarte          #+#    #+#             */
/*   Updated: 2024/10/28 01:15:17 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read malloc free
//return linea leida o null

#include <unistd.h>
char	*ft_get_next_line(int fd)
{
	static int	pos;
	char		*line;

	pos = 0;
	if (fd == -1)
        return (NULL);
	while ((read(fd, BUFF_SIZE, sizeof(char))) != '\n')
	{
  	}
}

int main ()
{
	char r = ft_get_next_line(open("txt.txt", 1));
	return (0);
}