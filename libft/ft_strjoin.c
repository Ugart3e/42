#include <stdlib.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	int totalsize;
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	if (!s1 || !s2)
		return NULL;
	while (*s1++)
		totalsize++;
	while (*s2++)
		totalsize++;
	char	s3[totalsize + 1];
	malloc(totalsize+1);
	while (s1[c1] != '\0')
		s3[c1] = s1[c1];
	while (s2[c2] != '\0')
		s3[c1 + c2] = s2[c2];
	s3[c1 + c2 + 1] = '\0';
	return (s3);
}