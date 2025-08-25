/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:27:07 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:08 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*generate_temp_filename(void)
{
	static int	counter = 0;
	char		*num_str;
	char		*filename;

	num_str = ft_itoa(counter++);
	filename = ft_strjoin("/tmp/heredoc_", num_str);
	free(num_str);
	return (filename);
}

static int	process_heredoc_content(char *delimiter, char *temp_file)
{
	int	fd;

	fd = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	if (!delimiter || delimiter[0] == '\0')
	{
		close(fd);
		return (1);
	}
	put_heredoc_prompt();
	if (!heredoc_loop(delimiter, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	is_redirection_token(int type)
{
	return (type == T_REDIRECTION_INFILE || type == T_REDIRECTION_OUTFILE
		|| type == T_APPEND || type == T_HEREDOC);
}

int	validate_syntax(t_tok *tokens)
{
	t_tok	*current;

	if (!tokens)
		return (1);
	if (starts_with_pipe(tokens))
		return (0);
	current = tokens;
	while (current)
	{
		if (is_syntax_error_at(current))
			return (0);
		current = current->next;
	}
	return (1);
}

int	handle_heredoc(t_cmd *cmd, char *delimiter)
{
	char	*temp_filename;

	temp_filename = generate_temp_filename();
	if (!temp_filename)
		return (0);
	if (!process_heredoc_content(delimiter, temp_filename))
	{
		free(temp_filename);
		return (0);
	}
	if (cmd->fdin != STDIN_FILENO)
		close(cmd->fdin);
	cmd->fdin = open(temp_filename, O_RDONLY);
	if (cmd->fdin == -1)
	{
		free(temp_filename);
		cmd->error = 1;
		return (0);
	}
	free(temp_filename);
	return (1);
}
