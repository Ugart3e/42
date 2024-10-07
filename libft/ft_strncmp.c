#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t count)
{
    size_t c = 0;
    while (c < count && s1[c] != '\0' && s2[c] != '\0')
	{
        if (s1[c] != s2[c])
            return ((unsigned char)s1[c] - (unsigned char)s2[c]);
        c++;
    }
    if (c < count)
        return ((unsigned char)s1[c] - (unsigned char)s2[c]);
    return (0);
}
