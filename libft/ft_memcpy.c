void    *ft_memcpy(void *destination, const void *source, int num)
{
    unsigned char   *dest;
    unsigned char   *src;

    if (!dest || !src)
        return (0);
    dest = (unsigned char *)destination;
    src = (unsigned char *)source;
    while (0 < num--)
        *(dest++) = *(src++);
    return ((void *)destination);
}