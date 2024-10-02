char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *res;
    
    res = malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!res)
        return (0);
    i = 0;
    while (i < ft_strlen(s))
    {
        res[i] = (*f)(i, s[i]);
        i++;
    }
    res[i] = 0;
    return (res);
}