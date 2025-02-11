/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:31:47 by jougarte          #+#    #+#             */
/*   Updated: 2025/02/11 15:25:10 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				current_position;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

//*** Handle input
char			**ft_split(char *str, char separator);
//Errors
void			free_matrix(char **argv);
void			error_free(t_list **a, char **argv, bool flag_argc_2);
void			free_stack(t_list **stack);
int				error_repetition(t_list *a, int nbr);
//Stacks management
void			stack_init(t_list **a, char **argv, bool flag_argc_2);
void			init_nodes(t_list *a, t_list *b);
void			set_current_position(t_list *stack);
void			set_price(t_list *a, t_list *b);
void			set_cheapest(t_list *b);
//linked lists
void			append_node(t_list **stack, int nbr);
t_list			*find_last_node(t_list *head);
t_list			*find_smallest(t_list *stack);
t_list			*return_cheapest(t_list *stack);
bool			stack_sorted(t_list *stack);
int				stack_len(t_list *stack);
void			finish_rotation(t_list **s, t_list *n, char c);
//Algorithms
void			tiny_sort(t_list **a);
void			handle_five(t_list **a, t_list **b);
void			push_swap(t_list **a, t_list **b);

//Commands
void			sa(t_list **a, bool checker);
void			sb(t_list **b, bool checker);
void			ss(t_list **a, t_list **b, bool checker);
void			ra(t_list **a, bool checker);
void			rb(t_list **b, bool checker);
void			rr(t_list **a, t_list **b, bool checker);
void			rra(t_list **a, bool checker);
void			rrb(t_list **b, bool checker);
void			rrr(t_list **a, t_list **b, bool checker);
void			pa(t_list **a, t_list **b, bool checker);
void			pb(t_list **b, t_list **a, bool checker);

#endif