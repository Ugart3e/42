#include <stdlib.h>

static int word_count(const char *str, char c);
static char *fill_word(const char *str, int start, int end);
static void *ft_free(char **strs, int count);
static void ft_initiate_vars(size_t *i, int *j, int *s_word);
static size_t ft_strlen(const char *str);
static void *ft_calloc(size_t count, size_t size);

char **ft_split(const char *s, char c)
{
    char **res;
    size_t i;
    int j;
    int s_word;

    ft_initiate_vars(&i, &j, &s_word);
    res = ft_calloc(word_count(s, c) + 1, sizeof(char *));
    if (!res)
        return (NULL);

    while (i < ft_strlen(s))
    {
        if (s[i] != c && s_word < 0)
            s_word = i;
        else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
        {
            res[j] = fill_word(s, s_word, i);
            if (!(res[j]))
                return (ft_free(res, j));
            s_word = -1;
            j++;
        }
        i++;
    }
    return (res);
}

static void ft_initiate_vars(size_t *i, int *j, int *s_word)
{
    *i = 0;
    *j = 0;
    *s_word = -1;
}

static void *ft_free(char **strs, int count)
{
    int i = 0;

    while (i < count)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
    return (NULL);
}

static char *fill_word(const char *str, int start, int end)
{
    char *word;
    int i = 0;

    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);

    while (start < end)
    {
        word[i] = str[start];
        i++;
        start++;
    }
    word[i] = '\0'; // Terminar la cadena
    return (word);
}

static int word_count(const char *str, char c)
{
    int count = 0;
    int x = 0;

    while (*str)
    {
        if (*str != c && x == 0)
        {
            x = 1;
            count++;
        }
        else if (*str == c)
            x = 0;
        str++;
    }
    return (count);
}

static size_t ft_strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0')
        length++;
    return (length);
}

static void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total_size = count * size;
    size_t i = 0;

    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);
    while (i < total_size)
    {
        ((char *)ptr)[i] = 0;
        i++;
    }
    return (ptr);
}