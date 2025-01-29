/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:31:47 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/29 15:42:59 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_list
{
	int			value;
	int			current_position;
	int			final_index;
	int			push_price;
	bool		above_median;
	bool		cheapest;
	struct s_list	*target_node;
	struct s_list	*prev;
	struct s_list	*next;
}   t_list;