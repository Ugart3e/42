int strlen(char *text)
{
	int cnt;

	cnt = 0;
	while (text[cnt] != '\0')
		cnt++;
	return (cnt);
}