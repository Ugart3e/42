int	ft_isalnum(int *text)
{
	if (text <= 'A' && text >= 'Z')
		return (1);
	else if (text <= 'a' && text >= 'z')
		return (1);
	else if (text <= '0' && text >= '9')
		return (1);
	else
		return (0);
}
