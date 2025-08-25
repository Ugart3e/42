/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:26:59 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:00 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*start_new_cmd(t_cmd **cmds, t_cmd **last_cmd)
{
	t_cmd	*new_cmd;

	new_cmd = create_cmd();
	if (!*cmds)
		*cmds = new_cmd;
	else
		(*last_cmd)->next = new_cmd;
	*last_cmd = new_cmd;
	return (new_cmd);
}

static void	handle_word_token(t_cmd **current_cmd, t_tok *token,
		t_cmd **cmds, t_cmd **last_cmd)
{
	if (!*current_cmd)
		*current_cmd = start_new_cmd(cmds, last_cmd);
	add_arg_to_cmd(*current_cmd, token->content);
}

static int	handle_redir_token(t_cmd *current_cmd, t_tok **token)
{
	if (current_cmd && handle_redirection(current_cmd, token))
		return (1);
	return (0);
}

static void	process_token(t_tok **current_token, t_cmd **current_cmd,
		t_cmd **cmds, t_cmd **last_cmd)
{
	if ((*current_token)->type == T_WORD
		|| (*current_token)->type == T_SIMPLE_QUOTE
		|| (*current_token)->type == T_DOUBLE_QUOTE)
	{
		handle_word_token(current_cmd, *current_token, cmds, last_cmd);
		*current_token = (*current_token)->next;
	}
	else if ((*current_token)->type == T_PIPE)
	{
		*current_cmd = NULL;
		*current_token = (*current_token)->next;
	}
	else if ((*current_token)->type == T_HEREDOC
		|| (*current_token)->type == T_APPEND
		|| (*current_token)->type == T_REDIRECTION_INFILE
		|| (*current_token)->type == T_REDIRECTION_OUTFILE)
	{
		if (!*current_cmd)
			*current_cmd = start_new_cmd(cmds, last_cmd);
		if (!handle_redir_token(*current_cmd, current_token))
			*current_token = (*current_token)->next;
	}
	else
		*current_token = (*current_token)->next;
}

t_cmd	*parse_tokens(t_tok *tokens)
{
	t_cmd	*cmds;
	t_cmd	*current_cmd;
	t_tok	*current_token;
	t_cmd	*last_cmd;

	cmds = NULL;
	current_cmd = NULL;
	last_cmd = NULL;
	current_token = tokens;
	while (current_token)
		process_token(&current_token, &current_cmd, &cmds, &last_cmd);
	return (cmds);
}
