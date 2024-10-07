#include <stddef.h>
char *strrchr(const char *s, int c) {
    const char *last = NULL;
    char character = (char)c;
    while (*s)
	{
        if (*s == character)
            last = s;
        s++;
    }
    return ((char *)last);
}