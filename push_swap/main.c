/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:05:43 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/29 13:03:59 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
//paso 1. Coger los numeros con atoi y meterlos en una ll
int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
    if(1 == argc || (2 == argc && !argv[1][0]))
        return (1);
    else if (2 == argc)
        argv = ft_split(argv[1], ' ');
    stack_init(&a, argv + 1, 2 == argv);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len(a) == 3)
            tiny_sort(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
}