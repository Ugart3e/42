/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:46:12 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/29 16:14:12 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void push_swap(t_list **a, t_list **b)
{
    t_list *smallest;
    int len_a;

    len_a = stack_len(a);
    if(len_a == 5)
        handle_five(a,b);
    else
    {
        while(len_a-- > 3)
            pb(b,a,false);
    }
    tiny_sort(a);
    while(*b)
    {
        init_nodes(*a, *b);
        move_nodes(a,b);
    }
    set_current_position(*a);
    smallest = find_smallest(*a);
    if (smallest->above_median)
        while(*a != smallest)
            ra(a, false);
    else
        while (*a != smallest)
            rra(a, false);
}

static void move_nodes(t_list **a, t_list **b)
{
    t_list *cheapest_node;

    cheapest_node = return_cheapest(*b);
    if(cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a,b,cheapest_node);
    else if(!cheapest_node->above_median && cheapest_node->target_node->above_median)
        reverse_rotate_both(a,b,cheapest_node);
    finish_rotation(b,cheapest_node, 'b');
    finish_rotation(a,cheapest_node->target_node, 'a');
    pa(a,b, false);
}