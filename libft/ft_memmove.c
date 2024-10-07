#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t numBytes) {
    char *d = (char *)dest;
    const char *s = (const char *)src;
    if (d == s || numBytes == 0) 
        return (dest);
    if (s < d) 
	{
        for (size_t i = numBytes; i > 0; i--)
            d[i - 1] = s[i - 1];
    } 
	else 
	{
        for (size_t i = 0; i < numBytes; i++)
            d[i] = s[i];
    }
    return (dest);
}