void    ft_bzero(void *s, int n)
{
    unsigned char   *ptr;
    
    ptr = (unsigned char *)s;
    while (n--)
    {
        *ptr = 0;
        *ptr++;
    }
}