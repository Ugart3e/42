#include <stddef.h>
char *strchr(const char *s, int c) {
    char character = (char)c;

    while (*s != character) {
        if (*s == '\0') {
            return (NULL);
        }
        s++;
    }
    return ((char *)s);
}
