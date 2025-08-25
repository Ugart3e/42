/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:05:35 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 17:08:10 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*process_quoted_content(char **input,
	char *complete_word, t_mnsh *data)
{
	char	quote_char;
	char	*content;
	char	*part;
	char	*temp;

	quote_char = **input;
	content = extract_quoted_content(input, quote_char);
	if (!content)
		return (complete_word);
	if (quote_char == '"')
		part = expand_variables_in_string(content, data);
	else
		part = ft_strdup(content);
	temp = ft_strjoin(complete_word, part);
	free(complete_word);
	free(content);
	free(part);
	return (temp);
}

char	*process_unquoted_content(char **input,
	char *complete_word, t_mnsh *data)
{
	char	*start;
	char	*part;
	char	*expanded_part;
	char	*temp;

	start = *input;
	while (**input && !(**input == ' ' || **input == '\t'
			|| **input == '|' || **input == '<' || **input == '>'
			|| **input == '\'' || **input == '"'))
		(*input)++;
	part = ft_substr(start, 0, *input - start);
	expanded_part = expand_if_variable(part, data);
	temp = ft_strjoin(complete_word, expanded_part);
	free(complete_word);
	free(part);
	free(expanded_part);
	return (temp);
}
