unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	c1;
	unsigned int	c2;
	unsigned int	i;

	c1 = 0;
	c2 = 0;
	i = 0;
	while (dest[c1] != '\0')
		c1++;
	while (src[c2] != '\0')
		c2++;
	while (src[i] != '\0' && i < size)
	{
		dest[c1 + i] = src[i];
		i++;
	}
	dest[c1 + c2] = '\0';
	return (c1 + c2);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "Worldiouasd";
	unsigned int siz = 2;
	char dest[] = "Hello ";
	unsigned int tot;
	tot = ft_strlcat(dest, str, siz);
	printf("%s\n", dest);
	printf("%d\n", tot);
}*/
