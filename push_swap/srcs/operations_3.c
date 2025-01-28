/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:37:11 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/26 19:39:14 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rb (rotate b) : shift up all elements of stack b by 1. 
// The first element becomes the last one.
void	ft_rb(t_list **b, int j)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

// sb (swap b) : swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
void	ft_sb(t_list **b, int j)
{
	t_list	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}