/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:28 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/11 16:46:54 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mostrar string recibida 
//Signals: SIGUSR1 y SIGUSR2

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

void signal_handler(int signal)
{
    static char c = 0;  //almacenar carácter
    static int bit_count = 0;

    if (signal == SIGUSR1)
        c |= (1 << (7 - bit_count));  // SIGUSR1,bit = 1
    //SIGUSR2, bit = 0
    bit_count++;

    //un carácter completo
    if (bit_count == 8) {
        ft_putchar(c);  // Imprimimos
        bit_count = 0;  // Reiniciar contador de bits
        c = 0;          // Reiniciar char
    }
}

void    showpid()
{
    int pid = getpid();
    ft_printf("Server PID: %d\n", pid);
}

int main()
{
    showpid();

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    pause();
    return 0;
}