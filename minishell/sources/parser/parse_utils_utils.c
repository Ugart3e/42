/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:27:03 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:04 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	starts_with_pipe(t_tok *tokens)
{
	return (tokens && tokens->type == T_PIPE);
}

static int	is_valid_after_redir(t_tok *tok)
{
	if (!tok)
		return (0);
	return (tok->type == T_WORD || tok->type == T_SIMPLE_QUOTE
		|| tok->type == T_DOUBLE_QUOTE);
}

int	is_syntax_error_at(t_tok *current)
{
	if (current->type == T_PIPE)
	{
		if (!current->next)
			return (1);
		if (current->next->type == T_PIPE)
			return (1);
		return (0);
	}
	if (is_redirection_token(current->type))
		return (!is_valid_after_redir(current->next));
	return (0);
}

void	put_heredoc_prompt(void)
{
	ft_putstr_fd("heredoc> ", STDERR_FILENO);
}

int	heredoc_loop(char *delimiter, int fd)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		put_heredoc_prompt();
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}
