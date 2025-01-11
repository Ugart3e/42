/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:37 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/11 17:35:09 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PID y string a enviar
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"

void send_char_signal(char c, int server_pid)
{
    int i = 0;
    while (i < 8)
    {
        if ((c >> (7 - i)) & 1)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        
        usleep(100);
        i++;
    }
}

// Función para enviar el string completo
void send_string(const char *str, int server_pid)
{
    while (*str) {
        send_char_signal(*str, server_pid);
		ft_printf("%c", *str);
        str++;
    }
    send_char_signal('\0', server_pid);
}

int main(int argc, char **argv)
{
    int server_pid;
    if (argc != 3) {
        ft_putstr("Error: Debes pasar el PID del servidor y el mensaje.\n");
        return 1;
    }
    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0) {
        ft_putstr("Error: El PID del servidor debe ser un número válido mayor que 0.\n");
        return 1;
    }
    if (ft_strlen(argv[2]) == 0) {
        ft_putstr("Error: El mensaje no puede estar vacío.\n");
        return 1;
    }
    send_string(argv[2], server_pid);
    return 0;
}