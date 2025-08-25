/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:46 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 17:01:35 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_var_end(char *str, int start)
{
	int	end;

	end = start;
	if (str[end] == '?')
		end++;
	else
	{
		while (str[end] && (ft_isalnum(str[end]) || str[end] == '_'))
			end++;
	}
	return (end);
}

static char	*get_expanded_value(char *str, int start, int end, t_mnsh *data)
{
	char	*var_name;
	char	*expanded;

	var_name = ft_substr(str, start, end - start);
	if (ft_strcmp(var_name, "?") == 0)
		expanded = ft_itoa(data->status);
	else
		expanded = expand_env_variable(var_name, data->env);
	free(var_name);
	return (expanded);
}

char	*process_variable(char **str_ptr, char *reslt, t_mnsh *data, int *i)
{
	char	*temp;
	char	*expanded;
	char	*new_result;
	int		var_end;

	temp = ft_substr(*str_ptr, 0, *i);
	new_result = ft_strjoin(reslt, temp);
	free(reslt);
	free(temp);
	reslt = new_result;
	var_end = find_var_end(*str_ptr, *i + 1);
	expanded = get_expanded_value(*str_ptr, *i + 1, var_end, data);
	new_result = ft_strjoin(reslt, expanded);
	free(reslt);
	free(expanded);
	*str_ptr += var_end;
	*i = 0;
	return (new_result);
}

static char	*handle_normal_variable(char *word, t_mnsh *data, int i)
{
	char	*var_name;
	char	*expanded;
	char	*temp;

	var_name = ft_substr(word, 1, i - 1);
	expanded = expand_env_variable(var_name, data->env);
	if (word[i])
	{
		temp = ft_strjoin(expanded, word + i);
		free(expanded);
		free(var_name);
		return (temp);
	}
	free(var_name);
	return (expanded);
}

char	*expand_if_variable(char *word, t_mnsh *data)
{
	int		i;

	if (!word || word[0] != '$')
		return (ft_strdup(word));
	if (ft_strlen(word) == 1)
		return (ft_strdup(word));
	if (word[1] == '?')
		return (handle_exit_status_case(word, data));
	i = 1;
	while (word[i] && (ft_isalnum(word[i]) || word[i] == '_'))
		i++;
	if (i == 1)
		return (ft_strdup(word));
	return (handle_normal_variable(word, data, i));
}
