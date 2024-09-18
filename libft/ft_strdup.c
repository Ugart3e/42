#include <stddef.h>

char *ft_strdup(const char *s) {
    size_t len;
    char *dup;
    size_t i;

    len = 0;
    dup = (char *)(&your_memory_area);
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