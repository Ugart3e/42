#include <stdlib.h>
#include <stddef.h>

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t totalsize = 0;
    size_t c1 = 0;
    size_t c2 = 0;
    if (!s1 || !s2)
        return NULL;
    while (s1[totalsize] != '\0')
        totalsize++;
    while (s2[c2] != '\0')
	{
        totalsize++;
        c2++;
    }
    char *s3 = (char *)malloc(totalsize + 1);
    if (!s3)
        return (NULL);
    while (s1[c1] != '\0')
	{
        s3[c1] = s1[c1];
        c1++;
    }
	while (s2[c2] != '\0') {
        s3[c1 + c2] = s2[c2];
        c2++;
    }
	s3[c1 + c2] = '\0';
    return (s3);
}
