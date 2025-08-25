/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:26:48 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:26:49 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ini_data(t_mnsh *data)
{
	data->cmd = NULL;
	data->env = NULL;
	data->export = NULL;
	data->tok = NULL;
	data->len_cmds = 0;
	data->pids = NULL;
	data->env = NULL;
	data->export = NULL;
	data->envp = NULL;
	data->status = 0;
}

static void	minishell_loop(t_mnsh *data)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			break ;
		}
		if (ft_strlen(input) > 0)
		{
			if (parse_input(input, data))
			{
				add_history(input);
				execute_process(data);
			}
		}
		free(input);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_mnsh	data;

	(void)ac;
	(void)av;
	init_signals();
	ini_data(&data);
	init_env(&data.env, envp);
	init_env(&data.export, envp);
	minishell_loop(&data);
	clear_history();
	ft_freemnsh(&data);
	return (data.status);
}
