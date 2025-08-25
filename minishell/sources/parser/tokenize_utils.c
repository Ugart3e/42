/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:27:15 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:16 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*create_token(char *content, int type)
{
	t_tok	*new;

	new = (t_tok *)malloc(sizeof(t_tok));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->type = type;
	new->next = NULL;
	return (new);
}

void	add_token(t_tok **tokens, t_tok *new)
{
	t_tok	*tmp;

	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	tmp = *tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	is_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == ' ' || c == '\t' || c == '\''
		|| c == '"')
		return (1);
	return (0);
}

char	*expand_env_variable(char *var_name, t_env *env)
{
	t_env	*current;

	if (!var_name || !env)
		return (ft_strdup(""));
	current = env;
	while (current)
	{
		if (current->name && ft_strcmp(current->name, var_name) == 0)
		{
			if (current->content)
				return (ft_strdup(current->content));
			else
				return (ft_strdup(""));
		}
		current = current->next;
	}
	return (ft_strdup(""));
}

char	*extract_quoted_content(char **input, char quote_char)
{
	char	*start;
	char	*content;
	int		len;

	(*input)++;
	start = *input;
	while (**input && **input != quote_char)
		(*input)++;
	if (!**input)
	{
		ft_putstr_fd("minishell: syntax error: unclosed quote\n", 2);
		return (NULL);
	}
	len = *input - start;
	content = ft_substr(start, 0, len);
	(*input)++;
	return (content);
}
