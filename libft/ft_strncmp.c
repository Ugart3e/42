int strncmp(const char *s1, const char *s2, int count)
{
	int	c;
	int	cnt;

	c = 0;
	cnt = 0;
	while (s1[c] != '\0' && s2[c] != '\0' && cnt <= count)
	{
		if (s1[c] != s2[c])
			return (s1[c] - s2[c]);
		c++;
	}
	return (s1[c] - s2[c]);
}
