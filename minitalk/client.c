/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:37 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/13 15:34:00 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PID y string a enviar
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"

// Función para enviar un solo carácter como una secuencia de bits
void send_char_signal(char c, int server_pid)
{
    int i = 0;
    while (i < 8)
    {
        if ((c >> (7 - i)) & 1) {
            kill(server_pid, SIGUSR1); // Enviar SIGUSR1 (bit = 1)
            ft_printf("Enviando bit 1\n"); // Depuración
        }
        else {
            kill(server_pid, SIGUSR2); // Enviar SIGUSR2 (bit = 0)
            ft_printf("Enviando bit 0\n"); // Depuración
        }

        usleep(100); // Pausa para evitar enviar señales demasiado rápido
        i++;
    }
}

// Función para enviar un string completo
void send_string(const char *str, int server_pid)
{
    while (*str) {
        send_char_signal(*str, server_pid); // Enviar cada carácter como bits
        str++;
    }
    send_char_signal('\0', server_pid); // Enviar carácter nulo al final
}

int main(int argc, char **argv)
{
    int server_pid;

    // Verificar que el número de argumentos sea correcto
    if (argc != 3) {
        ft_putstr("Error: Debes pasar el PID del servidor y el mensaje.\n");
        return 1;
    }

    // Obtener el PID del servidor y validarlo
    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0) {
        ft_putstr("Error: El PID del servidor debe ser un número válido mayor que 0.\n");
        return 1;
    }

    // Verificar que el mensaje no esté vacío
    if (ft_strlen(argv[2]) == 0) {
        ft_putstr("Error: El mensaje no puede estar vacío.\n");
        return 1;
    }

    // Enviar el mensaje al servidor
    ft_printf("Enviando mensaje: \"%s\" al servidor con PID %d\n", argv[2], server_pid);
    send_string(argv[2], server_pid);
    
    return 0;
}