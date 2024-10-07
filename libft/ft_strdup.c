#include <stdlib.h>
#include <stddef.h>

char *ft_strdup(const char *s) {
    size_t len = 0;
    char *dup;
    size_t i;
    while (s[len] != '\0')
        len++;
    dup = (char *)malloc(len + 1);
    if (dup == NULL)
        return (NULL);
    for (i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return (dup);
}
