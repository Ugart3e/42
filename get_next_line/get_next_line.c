/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:15:16 by jougarte          #+#    #+#             */
/*   Updated: 2024/11/11 11:42:04 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newline(int fd)
{
	char	*buffer;
	char	*tmp;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char *));
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (buffer);
	while (!ft_strchr(buffer, '\n'))
	{
		tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char *));
		if (read(fd, tmp, BUFFER_SIZE) <= 0)
		{
			free(tmp);
			break ;
		}
		buffer = ft_strjoin(buffer, tmp);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*trashline;
	char		*line;
	int			i;

	trashline = ft_newline(fd);
	if ((!trashline && !storage) || (trashline[0] == '\0' && !storage))
	{
		free(trashline);
		return (NULL);
	}
	trashline = ft_strjoin(storage, trashline);
	i = 0;
	while (trashline[i] != '\n' && trashline[i] != '\0')
		i++;
	line = ft_substr(trashline, 0, i + 1);
	if (trashline[i] == '\n')
		storage = ft_substr(trashline, i + 1, ft_strlen(trashline) - i - 1);
	else
		storage = NULL;
	free(trashline);
	return (line);
}
