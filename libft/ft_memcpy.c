#include <stddef.h>

void *ft_memcpy(void *destination, const void *source, size_t num) {
    unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    if (!dest && !src)
        return (NULL);

    while (num-- > 0) {
        *dest++ = *src++;
    }
    
    return (destination);
}
