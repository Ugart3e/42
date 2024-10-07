#include <stdlib.h>

static size_t ft_strlen(const char *str);

char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *res;

    if (!s)
        return (NULL);
    res = malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while (i < ft_strlen(s))
    {
        res[i] = f(i, s[i]);
        i++;
    }
    res[i] = '\0';
    return (res);
}

static size_t ft_strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0')
        length++;
    return (length);
}
