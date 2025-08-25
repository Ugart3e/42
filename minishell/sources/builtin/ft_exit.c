/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:24:44 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:24:49 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isnumber(char *nbr)
{
	int	i;

	if (!nbr || ft_strlen(nbr) == 0)
		return (0);
	i = 0;
	while (nbr[i] == 32 || (nbr[i] > 8 && nbr[i] < 14))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (!nbr[i])
		return (0);
	while (nbr[i])
	{
		if (ft_isdigit(nbr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isoverflow(char *str)
{
	if (ft_strlen(str) > 21)
		return (1);
	else if (ft_strlen(str) == 20
		&& ft_strcmp("-9223372036854775808", str) < 0)
		return (1);
	else if (ft_strlen(str) == 19
		&& ft_strcmp("9223372036854775807", str) < 0)
		return (1);
	else
		return (0);
}

static void	ft_exit_free(t_mnsh *data, int exitnbr)
{
	ft_freemnsh(data);
	exit(exitnbr);
}

void	ft_exit(t_cmd *cmd, t_mnsh *data)
{
	if (cmd->len_argv < 2)
	{
		ft_putendl_fd("exit", 2);
		ft_exit_free(data, data->status);
	}
	else
	{
		if (!ft_isnumber(cmd->argv[1]) || ft_isoverflow(cmd->argv[1]))
		{
			ft_putstr_fd("exit\nminishell: exit: ", 2);
			ft_putstr_fd(cmd->argv[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			ft_exit_free(data, 2);
		}
		else if (cmd->len_argv != 2)
		{
			ft_putendl_fd("exit\nminishell: exit: too many arguments", 2);
			data->status = 1;
		}
		else
		{
			ft_putendl_fd("exit", 2);
			ft_exit_free(data, ft_atoll(cmd->argv[1]) % 256);
		}
	}
}
