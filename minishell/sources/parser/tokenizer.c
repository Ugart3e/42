/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:27:20 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 17:05:33 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_special_token(char **input, t_tok **tokens)
{
	if (**input == '|')
		add_token(tokens, create_token("|", T_PIPE));
	else if (**input == '<' && *(*input + 1) == '<')
	{
		add_token(tokens, create_token("<<", T_HEREDOC));
		(*input)++;
	}
	else if (**input == '>' && *(*input + 1) == '>')
	{
		add_token(tokens, create_token(">>", T_APPEND));
		(*input)++;
	}
	else if (**input == '<')
		add_token(tokens, create_token("<", T_REDIRECTION_INFILE));
	else if (**input == '>')
		add_token(tokens, create_token(">", T_REDIRECTION_OUTFILE));
	(*input)++;
}

static void	skip_spaces(char **input)
{
	while (**input && (**input == ' ' || **input == '\t'))
		(*input)++;
}

static void	process_complex_word(char **input, t_tok **tokens, t_mnsh *data)
{
	char	*complete_word;

	complete_word = ft_strdup("");
	while (**input && !(**input == ' ' || **input == '\t'
			|| **input == '|' || **input == '<' || **input == '>'))
	{
		if (**input == '\'' || **input == '"')
			complete_word = process_quoted_content(input, complete_word, data);
		else
			complete_word = process_unquoted_content
				(input, complete_word, data);
	}
	if (complete_word && ft_strlen(complete_word) > 0)
		add_token(tokens, create_token(complete_word, T_WORD));
	free(complete_word);
}

t_tok	*tokenize(char *input, t_mnsh *data)
{
	t_tok	*tokens;
	char	*str;

	tokens = NULL;
	str = input;
	while (*str)
	{
		skip_spaces(&str);
		if (!*str)
			break ;
		if (*str == '|' || *str == '<' || *str == '>')
			process_special_token(&str, &tokens);
		else
			process_complex_word(&str, &tokens, data);
	}
	return (tokens);
}
