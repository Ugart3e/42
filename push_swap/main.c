/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:05:43 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/26 20:20:51 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//paso 1. Coger los numeros con atoi y meterlos en una ll
int main(int argc, char *argv[])
{

    int cantidad = argc - 1;
    int numeros[cantidad];

    for (int i = 0; i < cantidad; i++)
    {
        numeros[i] = atoi(argv[i + 1]);
    }
    for (int c = 0; c < cantidad; c++)
    {
        printf("%d ", numeros[c]);
    }
    return 0;
}