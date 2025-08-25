/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:38 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:42:16 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_process_multi_cmd(t_mnsh *data, t_cmd *cmd, int i)
{
	ft_redir_pipes(data, cmd, i);
	execute_multi_cmd(data, cmd, i);
	if (cmd->fdin != STDIN_FILENO)
		close(cmd->fdin);
	if (cmd->fdout != STDOUT_FILENO)
		close(cmd->fdout);
}

int	is_builtin(t_cmd *cmd, t_mnsh *data)
{
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (ft_echo(cmd, data), 1);
	else if (!ft_strcmp(cmd->argv[0], "cd"))
		return (ft_cd(cmd, data), 1);
	else if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (ft_pwd(cmd, data), 1);
	else if (!ft_strcmp(cmd->argv[0], "export"))
		return (ft_export(cmd, data), 1);
	else if (!ft_strcmp(cmd->argv[0], "unset"))
		return (ft_unset(cmd, data), 1);
	else if (!ft_strcmp(cmd->argv[0], "env"))
		return (ft_env(data->env, cmd), 1);
	else if (!ft_strcmp(cmd->argv[0], "exit"))
		return (ft_exit(cmd, data), 1);
	else
		return (0);
}

void	execute_multi_cmd(t_mnsh *data, t_cmd *cmd, int i)
{
	data->pids[i] = fork();
	if (data->pids[i] == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (!redir_in_out(cmd))
		{
			if (cmd->fdin != STDIN_FILENO && cmd->fdin != -1)
				close(cmd->fdin);
			if (cmd->fdout != STDOUT_FILENO && cmd->fdout != -1)
				close(cmd->fdout);
			exit (1);
		}
		if (is_builtin(cmd, data))
			exit(0);
		else
			execute_multi_cmd_process(data, cmd);
	}
}

void	execute_one_cmd(t_mnsh *data)
{
	char	*cmd;

	if (!redir_in_out(data->cmd))
	{
		data->status = 1;
		return ;
	}
	if (!is_builtin(data->cmd, data))
	{
		if (!data->cmd->argv || data->cmd->argv[0] == NULL)
			return ;
		env_generator(data);
		cmd = get_path(data->envp, data->cmd->argv[0]);
		if (!cmd)
		{
			ft_failpath(data->cmd->argv, cmd);
			data->status = 127;
			return ;
		}
		data->pids[0] = fork();
		if (data->pids[0] == 0)
			execute_one_cmd_process(data, cmd);
		free(cmd);
	}
}

void	execute_process(t_mnsh *data)
{
	t_cmd	*cmd;
	int		saved_stdout;
	int		saved_stdin;
	int		i;

	i = 0;
	calculate_cmd_len(data);
	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	cmd = data->cmd;
	if (!cmd->next || cmd->next == NULL)
		execute_one_cmd(data);
	else
	{
		while (cmd)
		{
			execute_process_multi_cmd(data, cmd, i);
			i++;
			cmd = cmd->next;
		}
	}
	execution_cleaner(data, saved_stdin, saved_stdout);
}
