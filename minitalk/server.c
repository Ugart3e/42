/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:13:20 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/13 17:22:57 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

void	signal_handler(int signal)
{
	static char	c = 0;
	static int	bit_count = 0;

	if (signal == SIGUSR1)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", c);
		bit_count = 0;
		c = 0;
	}
}

void	showpid(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
}

int	main(void)
{
	showpid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
