/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:31:47 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/26 19:58:12 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}   t_list;