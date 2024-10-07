int ft_toupper(int src)
{
    if (src >= 'a' && src <= 'z')
        return src - 32;
    return src;
}
