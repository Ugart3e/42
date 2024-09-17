void    *ft_memmove(void *dest, const void *src, int numBytes)
{
    unsigned int    i;
    char*   d; 
    char*   s;

    i = 0;
    d = (char*)dest;
    s = (char*)src;
    if (s >= d)
    {
        while (i <= numBytes)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        while (i < numBytes)
        {
            d[i] = s[i];
            i++;
        }
    }
}