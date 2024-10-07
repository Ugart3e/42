#include <stdlib.h>

static int to_trim(const char *set, char c);
static char *new_str(const char *s1, size_t start, size_t end);
static size_t ft_strlen(const char *str);
static char *ft_strdup(const char *s);
static void *ft_calloc(size_t count, size_t size);

char *ft_strtrim(const char *s1, const char *set)
{
    size_t i;
    size_t j;

    i = 0;
    j = ft_strlen(s1) - 1;
    if (ft_strlen(s1) == 0)
        return (ft_strdup(""));
    while (to_trim(set, s1[i]))
        i++;
    while (to_trim(set, s1[j]) && j > i) // Asegurarse de no cruzar índices
        j--;
    return new_str(s1, i, j + 1); // j + 1 para incluir el carácter final
}

static char *new_str(const char *s1, size_t start, size_t end)
{
    char *str;
    size_t i;

    if (end <= start || start >= ft_strlen(s1))
        return ft_strdup("");
    str = ft_calloc(end - start + 1, sizeof(char)); // end - start + 1 para espacio de terminación
    if (!str)
        return (NULL);
    i = 0;
    while (i < (end - start))
    {
        str[i] = s1[start + i];
        i++;
    }
    str[i] = '\0'; // Terminar la cadena
    return (str);
}

static int to_trim(const char *set, char c)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}

static size_t ft_strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0')
        length++;
    return (length);
}

static char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *dup = malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);

    size_t i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

static void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total_size = count * size;
    size_t i;

    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);

    i = 0;
    while (i < total_size)
    {
        ((char *)ptr)[i] = 0;
        i++;
    }
    return (ptr);
}
