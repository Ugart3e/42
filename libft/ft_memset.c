//1: turn ptr to byte, 2: Asign value to position, 3: return pointer
void    *memset(void *ptr, int value, int num) {
    unsigned char *p; 
    
    p = (unsigned char *)ptr;
    while (num--)
        *p++ = (unsigned char)value;
    return (ptr);
}
