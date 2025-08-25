/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:51 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:55 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_infile(t_cmd *cmd, char *filename)
{
	if (cmd->fdin != STDIN_FILENO)
		close(cmd->fdin);
	cmd->fdin = open(filename, O_RDONLY);
	if (cmd->fdin == -1)
	{
		cmd->error = 1;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
}

static void	handle_outfile(t_cmd *cmd, char *filename)
{
	if (cmd->error)
		return ;
	if (cmd->fdout != STDOUT_FILENO)
		close(cmd->fdout);
	cmd->fdout = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->fdout == -1)
	{
		cmd->error = 1;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
}

static void	handle_append(t_cmd *cmd, char *filename)
{
	if (cmd->error)
		return ;
	if (cmd->fdout != STDOUT_FILENO)
		close(cmd->fdout);
	cmd->fdout = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->fdout == -1)
	{
		cmd->error = 1;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
}

int	handle_redirection(t_cmd *cmd, t_tok **token)
{
	t_tok	*current;
	t_tok	*file_token;

	current = *token;
	file_token = current->next;
	if (!file_token || (file_token->type != T_WORD
			&& file_token->type != T_SIMPLE_QUOTE
			&& file_token->type != T_DOUBLE_QUOTE))
		return (0);
	if (current->type == T_REDIRECTION_INFILE)
		handle_infile(cmd, file_token->content);
	else if (current->type == T_REDIRECTION_OUTFILE)
		handle_outfile(cmd, file_token->content);
	else if (current->type == T_APPEND)
		handle_append(cmd, file_token->content);
	else if (current->type == T_HEREDOC)
	{
		if (!handle_heredoc(cmd, file_token->content))
			return (0);
	}
	*token = file_token->next;
	return (1);
}
