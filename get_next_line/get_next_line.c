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