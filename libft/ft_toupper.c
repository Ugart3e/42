char ft_toupper  (char *src)
{
    char    character;

    character = '';
    if (src >= 'a' && src <= 'z')
        character = (src - 32);
    else
        character = src;
    return (character);
}