int ft_tolower(int src)
{
    if (src >= 'A' && src <= 'Z')
        return src + 32;
    return src;
}
