/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:08 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:09 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(char *name)
{
	int	i;

	if (!name || !*name)
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	is_env(char *name, t_env *env)
{
	t_env	*temp_env;

	temp_env = env;
	while (temp_env)
	{
		if (!ft_strcmp(temp_env->name, name))
			return (1);
		temp_env = temp_env->next;
	}
	return (0);
}

static void	ft_change_content_env(t_env *env, char *name, char *content)
{
	t_env	*temp_env;

	temp_env = env;
	while (temp_env)
	{
		if (!ft_strcmp(temp_env->name, name))
		{
			free(temp_env->content);
			if (content)
				temp_env->content = ft_strdup(content);
			else
				temp_env->content = NULL;
		}
		temp_env = temp_env->next;
	}
}

static void	ft_addenv(t_mnsh *data, char *name, char *content)
{
	if (content)
		ft_envadd_back(&data->env, ft_envnew(name, content));
	if (is_env(name, data->export))
		ft_change_content_env(data->export, name, content);
	else
		ft_envadd_back(&data->export, ft_envnew(name, content));
}

void	ft_export_arg(t_mnsh *data, char *name, char *content, char *arg)
{
	if (arg && arg[0] == '-' && arg[1])
		export_invalid_option_msg(data, arg);
	else if (!is_valid_identifier(name))
		export_invalid_identifier_msg(data, arg);
	else
	{
		if (is_env(name, data->env))
		{
			ft_change_content_env(data->env, name, content);
			ft_change_content_env(data->export, name, content);
		}
		else
			ft_addenv(data, name, content);
		data->status = 0;
	}
	ft_free_name_content(name, content);
}
