void    *memcpy(void *destination, const void *source, int num)
{
    unsigned char   *dest;
    unsigned char   *src;

    dest = (unsigned char *)destination;
    src = (unsigned char *)source;
    while (num--)
    {
        *dest = *src;
    }
}