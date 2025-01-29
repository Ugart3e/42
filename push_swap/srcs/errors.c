/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:47:40 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/28 16:50:34 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int error_repetition(t_list *a, int nbr)
{
    if (NULL == a)
        returrn (0);
    while (a)
    {
        if (a->value == nbr)
            return(1);
        a = a->next;
    }
    return (0);
}