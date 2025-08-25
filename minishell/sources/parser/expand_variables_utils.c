/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:50:15 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:57:58 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_invalid_dollar(char *str, char *result, int *i)
{
	char	*temp;
	char	*new_result;

	temp = ft_substr(str, 0, *i);
	new_result = ft_strjoin(result, temp);
	free(result);
	free(temp);
	result = new_result;
	temp = ft_strdup("$");
	new_result = ft_strjoin(result, temp);
	free(result);
	free(temp);
	result = new_result;
	str += *i + 1;
	*i = 0;
	return (result);
}

char	*expand_variables_in_string_loop(char *str, char *result, t_mnsh *data)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1]
			&& (ft_isalnum(str[i + 1]) || str[i + 1] == '_'
				|| str[i + 1] == '?'))
			result = process_variable(&str, result, data, &i);
		else if (str[i] == '$' && (!str[i + 1]
				|| (!ft_isalnum(str[i + 1])
					&& str[i + 1] != '_' && str[i + 1] != '?')))
			result = handle_invalid_dollar(str, result, &i);
		else
			i++;
	}
	return (result);
}

char	*expand_variables_in_string(char *str, t_mnsh *data)
{
	char	*result;
	char	*new_result;

	if (!str)
		return (ft_strdup(""));
	result = ft_strdup("");
	result = expand_variables_in_string_loop(str, result, data);
	if (str[0])
	{
		new_result = ft_strjoin(result, str);
		free(result);
		return (new_result);
	}
	return (result);
}

char	*handle_exit_status_case(char *word, t_mnsh *data)
{
	char	*result;
	char	*temp;

	result = ft_itoa(data->status);
	if (word[2])
	{
		temp = ft_strjoin(result, word + 2);
		free(result);
		return (temp);
	}
	return (result);
}
