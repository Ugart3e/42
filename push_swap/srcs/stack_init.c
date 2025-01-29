/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:32:11 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/29 12:51:44 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long ft_atol(const char *str)
{
    long    num;
    int     neg;
    int     i;

    num = 0;
    neg = 1;
    i = 0;
    while(str[i] && str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '+')
      i++;
    else if(str[i] == '-')
    {
        neg *= -1;
        i++;
    }  
    while(str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return (num * neg);
        
}

void    stack_init(t_list **a , char **argv, bool checker)
{
    long nbr;
    while(*argv)
    {
        nbr = atol(*argv);
        if (nbr > INT_MAX || nbr < INT_MIN)
            error_free(a, argv, checker);
        if (error_repetition(*a, (int)nbr))
            error_free(a, argv, checker);
        append_node(a, (int)nbr);
        ++argv;
        printf("%p pointer from main change only once when changing from NULL to 1", a);
    }
}

void append_node(t_list **stack, int nbr)
{
    t_list *node;
    t_list *last_node;
    
    if(NULL == stack)
        return ;
    node = malloc(sizeof(t_list));
    if(NULL == node)
        return ;
    node -> next = NULL;
    node -> value = nbr;
    if(NULL == *stack)
    {
        *stack = node;
        node -> prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

void error_free(t_list **a, char **argv, bool checker)
{
    exit(2);
}

