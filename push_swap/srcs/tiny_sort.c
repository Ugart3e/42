/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:53:09 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/29 15:41:51 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool stack_sorted(t_list *stack)
{
    if (NULL == stack)
        return (NULL);
    while(stack -> next)
    {
        if (stack -> value > stack -> next -> value)
            return(false);
        stack = stack -> next;
    }
    return (true);
}

static t_list *find_highest(t_list *stack)
{
    int highest;
    t_list highest_node;
    
    highest = INT_MIN;
    if (NULL == stack)
        return (NULL);
    while (stack)
    {
        if(stack -> value > highest)
        {
            highest = stack -> value;
            highest_node = stack;
        }
        stack = stack -> next;
    }
}

void tiny_sort(t_list **a)
{
    t_list *highest_node;

    highest_node = find_highest(*a);
    if (*a == highest_node)
        ra(a, false);
    else if((*a)->next == highest_node)
        rra(a,false);
    if((*a)->value > (*a)->next->value)
        sa(a,false);
}

void handle_five(t_list **a, t_list **b)
{
    while(stack_len(*a) > 3)
    {
        init_nodes(*a, *b);
        finish_rotation(a, find_smallest(*a), 'a');
        pb(b, a, false);
    }
}

static void set_target_node(t_list *a, t_list *b)
{
    t_list *current_a;
    t_list *target_node;
    long    best_match_index;

    while (b)
    {
        best_match_index = LONG_MAX;
        current_a = a; 
        while (current_a)
        {
            if (current_a -> value > b -> value
                && current_a ->value < best_match_index)
            {
                best_match_index = current_a -> value;
                target_node = current_a;
            }
            current_a = current_a -> next;
        }
        if(LONG_MAX == best_match_index)
            b->target_node = find_smallest(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}