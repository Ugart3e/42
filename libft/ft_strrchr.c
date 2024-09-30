//The  strchr()  function  returns  a  pointer to the first occurrence of the character c in the string s.
char *strrchr(const char *s, int c)
{
	int cnt;
	int last;
	char	character;
	char	save;

	save = 'a';
	last = 0;
	cnt = 0;
	character = (char)c;
	while (s[cnt] != '\0')
	{
		if (s[cnt] == character)
		{
			save = s[cnt];
			cnt++;
		}
		else
			cnt++;
	}
	return (save);
}