/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:34 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:35 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	calculate_cmd_len(t_mnsh *data)
{
	int		i;
	t_cmd	*cmd_tmp;

	i = 0;
	cmd_tmp = data->cmd;
	while (cmd_tmp)
	{
		i++;
		cmd_tmp = cmd_tmp->next;
	}
	data->len_cmds = i;
	data->pids = ft_calloc(sizeof(int), i);
}

void	ft_redir_pipes(t_mnsh *msh, t_cmd *cmd, int i)
{
	int	fdpipe[2];

	if (cmd->fdin == -1 && !cmd->error)
		cmd->fdin = STDIN_FILENO;
	if (i == (msh->len_cmds - 1))
	{
		if (cmd->fdout == -1)
			cmd->fdout = STDOUT_FILENO;
	}
	else
	{
		pipe(fdpipe);
		if (cmd->next->fdin == -1 && !cmd->next->error)
			cmd->next->fdin = fdpipe[0];
		else
			close(fdpipe[0]);
		if (cmd->fdout == -1)
			cmd->fdout = fdpipe[1];
		else
			close(fdpipe[1]);
	}
}

int	redir_in_out(t_cmd *cmd)
{
	if (cmd->error)
		return (0);
	if (cmd->fdin != -1 && cmd->fdin != STDIN_FILENO)
	{
		if (cmd->fdin == -1)
			return (0);
		if (dup2(cmd->fdin, STDIN_FILENO) == -1)
			return (0);
		close(cmd->fdin);
	}
	if (cmd->fdout != -1 && cmd->fdout != STDOUT_FILENO)
	{
		if (cmd->fdout == -1)
			return (0);
		if (dup2(cmd->fdout, STDOUT_FILENO) == -1)
			return (0);
		close(cmd->fdout);
	}
	return (1);
}

void	execution_cleaner(t_mnsh *data, int saved_stdin, int saved_stdout)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->len_cmds)
	{
		if (data->pids[i] > 0)
		{
			waitpid(data->pids[i], &status, 0);
			if (i == data->len_cmds - 1)
				data->status = WEXITSTATUS(status);
		}
		i++;
	}
	ft_close_free_execut(data, saved_stdin, saved_stdout);
}
