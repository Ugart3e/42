#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

void signal_handler(int signal)
{
    static char c = 0;
    static int bit_count = 0;

    if (signal == SIGUSR1)
        c |= (1 << (7 - bit_count));

    bit_count++;

    // Cuando se recibe un byte completo (8 bits)
    if (bit_count == 8) {
        ft_printf("%c", c);  // Imprimir el carácter con mensaje de depuración
        bit_count = 0;  // Reiniciar contador de bits
        c = 0;          // Reiniciar el carácter
    }
}

void showpid()
{
    int pid = getpid();
    ft_printf("Server PID: %d\n", pid);
}

int main()
{
    showpid();

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1) {
        pause(); 
    }

    return 0;
}