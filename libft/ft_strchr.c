//The  strchr()  function  returns  a  pointer to the first occurrence of the character c in the string s.
char *strchr(const char *s, int c)
{
    int cnt;
    char    character;

    cnt = 0;
    character = (char)c;
    while (s[cnt] != character && s[cnt] != '\0')
        cnt++;
    if (s[cnt] == character)
        return (s[cnt]);
    else
        return (0);
}