int ft_isalpha(int *text)
{
    int cnt;

    if (text <= 'A' && text >= 'Z')
        return (1);
    else if (text <= 'a' && text >= 'z')
        return (1);
    else
        return (0);
}