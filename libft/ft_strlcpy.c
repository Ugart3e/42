int ft_strlcpy(char *dest, char *src, int size)
{
	int totalsize;
	int cnt1;
	int cnt2;

	totalsize = 0;
	cnt1 = 0;
	cnt2 = 0;
	while (src[cnt1] != '\0')
	{
		totalsize++;
		cnt1++;
	}
	while (dest[cnt2] != '\0')
	{
		totalsize++;
		cnt2++;
	}
	cnt1 = 0;
	cnt2 = 0;
	if (size >= totalsize)
	{
		while (src[cnt1] != '\0')
		{
			dest[cnt1] = src[cnt1];
			cnt1++;
		}
		while (cnt1 + cnt2 < size)
		{
			dest[cnt2] = '\0';
			cnt2++;
		}
	}
	return (totalsize);
}