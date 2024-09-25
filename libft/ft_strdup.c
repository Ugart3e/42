#include <stdlib.h>

char *ft_strdup(const char *s) {
    size_t len;
    char *dup;
    size_t i;

    len = 0;
    dup = (char *)malloc(len + 1);
    i = 0;
    while (s[len] != '\0') {
        len++;
    }
    if (dup == NULL) {
        return NULL;
    }
    while (i < len) {
        dup[i] = s[i];
        i++;
    }
    dup[len] = '\0';
    return dup;
}