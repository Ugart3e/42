/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:57:08 by jougarte          #+#    #+#             */
/*   Updated: 2024/08/13 23:30:29 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	argnum;
	int	c;
	int	i;
	int	sm;

	c = argc - 1;
	while (c > 0 && c--)
	{
		argnum = 1;
		sm = 1;
		while (argnum != (argc - 1) && argnum++)
		{
			i = 0;
			while (argv[argnum][i] == argv[sm][i])
				i++;
			if (argv[argnum][i] < argv[sm][i])
				sm = argnum;
		}
		i = 0;
		while (argv[sm][i])
			write (1, &argv[sm][i++], 1);
		argv[sm][0] = 127;
		write (1, "\n", 1);
	}
	return (0);
}
