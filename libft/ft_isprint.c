int ft_isprint(int *num)
{
    if (num >= 32 && num <= 126)
        return (1);
    else
        return (0);
}