/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:24:29 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:24:31 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_isnoption(char *str)
{
	int	i;

	if (str && !ft_strncmp(str, "-n", 2))
	{
		i = 1;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_echo(t_cmd *cmd, t_mnsh *data)
{
	int	i;
	int	no_newline;

	i = 1;
	no_newline = 0;
	while (ft_isnoption(cmd->argv[i]))
	{
		no_newline = 1;
		i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr(cmd->argv[i]);
		if ((i + 1) < cmd->len_argv)
			ft_putstr(" ");
		i++;
	}
	if (!no_newline)
		ft_putstr("\n");
	data->status = 0;
}
