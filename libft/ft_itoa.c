#include <stdlib.h>

static int int_len(long nbr);
static char *pre_conv(int len);

char *ft_itoa(int n)
{
    int len;
    int i;
    char *result;
    long nbr;

    nbr = n;
    len = int_len(nbr);
    result = pre_conv(len);
    if (!result)
        return (NULL);
    i = len - 1;
    if (nbr == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    if (n < 0)
    {
        nbr = -nbr;
        result[0] = '-';
    }
    while (nbr != 0)
    {
        result[i--] = (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    result[len] = '\0';
    return (result);
}
static char *pre_conv(int len)
{
    char *tmp;

    tmp = malloc((len + 1) * sizeof(char));
    if (!tmp)
        return (NULL);
    return tmp;
}
static int int_len(long nbr)
{
    int count = 0;
    if (nbr < 0)
    {
        count++;
        nbr = -nbr;
    }
    if (nbr == 0)
        count++;
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    return (count);
}