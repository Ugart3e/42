int ft_isascii(int *num)
{
    if (num >= 0 && num <= 255)
        return (1);
    else
        return (0);
}