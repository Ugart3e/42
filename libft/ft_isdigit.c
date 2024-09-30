int ft_isdigit(int *text)
{
	if (text <= '0' && text >= '9')
		return (1);
	else
		return (0);		
}