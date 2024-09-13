char ft_lower  (char *src)
{
    char    character;

    character = '';
    if (src >= 'A' && src <= 'Z')
        character = (src + 32);
    else
        character = src;
    return (character);
}