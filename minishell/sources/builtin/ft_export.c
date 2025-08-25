/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:19 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:20 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_shorted(t_env *env)
{
	t_env	*temp_env;

	temp_env = env;
	while (temp_env && temp_env->next)
	{
		if (ft_strcmp(temp_env->name, temp_env->next->name) > 0)
			return (0);
		temp_env = temp_env->next;
	}
	return (1);
}

static void	ft_short_export(t_env *export)
{
	t_env	*temp_export;

	while (!is_shorted(export))
	{
		temp_export = export;
		while (temp_export && temp_export->next)
		{
			if (ft_strcmp(temp_export->name, temp_export->next->name) > 0)
			{
				ft_swap(&temp_export->name, &temp_export->next->name);
				ft_swap(&temp_export->content, &temp_export->next->content);
			}
			temp_export = temp_export->next;
		}
	}
}

static void	ft_print_export(t_mnsh *data)
{
	t_env	*temp_export;

	ft_short_export(data->export);
	temp_export = data->export;
	while (temp_export)
	{
		if (!temp_export->content)
			printf("declare -x %s\n", temp_export->name);
		else
			printf
				("declare -x %s=\"%s\"\n",
					temp_export->name, temp_export->content);
		temp_export = temp_export->next;
	}
}

static int	ft_process_export_arg(t_cmd *cmd, t_mnsh *data, int argv)
{
	char	*name;
	char	*content;
	int		i;

	content = NULL;
	i = 0;
	while (cmd->argv[argv][i] && cmd->argv[argv][i] != '=')
		i++;
	name = ft_substr(cmd->argv[argv], 0, i);
	if (ft_strchr(cmd->argv[argv], '='))
		content = ft_strdup(ft_strchr(cmd->argv[argv], '=') + 1);
	data->status = 0;
	ft_export_arg(data, name, content, cmd->argv[argv]);
	return (data->status);
}

void	ft_export(t_cmd *cmd, t_mnsh *data)
{
	int		argv;
	int		error_status;

	argv = 1;
	error_status = 0;
	if (cmd->len_argv > 1)
	{
		while (argv != cmd->len_argv)
		{
			ft_process_export_arg(cmd, data, argv);
			if (data->status != 0)
				error_status = data->status;
			argv++;
		}
		data->status = error_status;
	}
	else
	{
		ft_print_export(data);
		data->status = 0;
	}
}
