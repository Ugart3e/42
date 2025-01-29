/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:51 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/29 16:09:31 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

t_list  *find_last_node(t_list *head)
{
    if(NULL == head)
        return (NULL);
    while(head -> next)
        head = head -> next;
    return (head);
}

t_list  *find_smallest(t_list *stack)
{
    long smallest;
    t_list *smallest_node;

    if(NULL == stack)
        return (NULL);
    smallest = LONG_MAX;
    while(stack)
    {
        if (stack -> value < smallest)
        {
            smallest = stack -> value;
            smallest_node = stack;
        }
        stack = stack -> next;
    }
    return (smallest_node);
}

t_list *return_cheapest(t_list *stack)
{
    if (NULL == stack)
        return (NULL);
    while(stack)
    {
        if (stack -> cheapest)
            return (stack);
        stack = stack -> next;
    }
    return (NULL);
}

t_list *stack_len(t_list *stack)
{
    int count;

    count = 0;
    if (NULL == stack)
        return (NULL);
    while (stack)
    {
        count++;
        stack = stack -> next;   
    }
    return (count);
}

void set_price(t_list *a, t_list *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while(b)
    {
        b->push_price = b-> current_position;
        if(!(b->above_median))
            b->push_price = len_b - (b->current_position);
            if(b->target_node->above_median)
                b->push_price += len_a - (b -> target_node->current_position);
            b = b->next;
    }
}

void set_cheapest(t_list *b)
{
    long best_match_value;
    t_list *best_match_node;
    
    if(NULL == b)
        return ;
    best_match_value = LONG_MAX;
    while(b)
    {
        if(b->push_price < best_match_value)
        {
            best_match_value = b -> push_price;
            best_match_node = b;
        }
        b = b->next;
    }
    best_match_node -> cheapest = true;
}