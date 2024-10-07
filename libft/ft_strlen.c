#include <stddef.h>

int ft_strlen(const char *text) {
    int cnt = 0;
    while (text[cnt] != '\0')
        cnt++;
    return (cnt);
}
