/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:15:16 by jougarte          #+#    #+#             */
/*   Updated: 2024/11/11 12:18:18 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_newline(int fd)
{
	char	*buffer;
	char	*tmp;

	buffer = ft_callocgnl((BUFFER_SIZE + 1), sizeof(char *));
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (buffer);
	while (!ft_strchrgnl(buffer, '\n'))
	{
		tmp = ft_callocgnl((BUFFER_SIZE + 1), sizeof(char *));
		if (read(fd, tmp, BUFFER_SIZE) <= 0)
		{
			free(tmp);
			break ;
		}
		buffer = ft_strjoingnl(buffer, tmp);
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
	trashline = ft_strjoingnl(storage, trashline);
	i = 0;
	while (trashline[i] != '\n' && trashline[i] != '\0')
		i++;
	line = ft_substrgnl(trashline, 0, i + 1);
	if (trashline[i] == '\n')
		storage = ft_substrgnl(trashline, i + 1, ft_strlengnl(trashline) - i);
	else
		storage = NULL;
	free(trashline);
	return (line);
}

int main()
{
	int fd = open("txt.txt", O_RDONLY);
    char *r;
    int i = 0;
    while (i < 10)
    {
        r = get_next_line(fd);
        if (r)
        {
            printf("%s", r);
            free(r);
        }
        else
            break;
        i++;
    }
    close(fd);
    return 0;
}
