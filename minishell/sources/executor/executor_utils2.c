/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:31:30 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:41:30 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_one_cmd_process(t_mnsh *data, char *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(cmd, data->cmd->argv, data->envp);
}

void	execute_multi_cmd_process(t_mnsh *data, t_cmd *cmd)
{
	char	*path;

	if (!cmd->argv || cmd->argv[0] == NULL)
		exit(0);
	env_generator(data);
	path = get_path(data->envp, cmd->argv[0]);
	if (!path)
	{
		ft_failpath(cmd->argv, path);
		exit(127);
	}
	execve(path, cmd->argv, data->envp);
	free(path);
	exit(127);
}
