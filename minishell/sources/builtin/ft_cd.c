/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:24:15 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:24:18 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_dir_error(char *argv, t_mnsh *data)
{
	ft_putstr_fd("bash: cd: ", 2);
	ft_putstr_fd(argv, 2);
	ft_putendl_fd(": No such file or directory", 2);
	data->status = 1;
}

static void	print_option_error(char *argv, t_mnsh *data)
{
	ft_putstr_fd("bash: cd: -", 2);
	ft_putchar_fd(argv[1], 2);
	ft_putendl_fd(": invalid option", 2);
	data->status = 2;
}

static void	change_env_oldpwd(t_mnsh *data, char *oldpwd)
{
	t_env	*temp_env;

	temp_env = data->env;
	while (temp_env)
	{
		if (ft_strcmp("OLDPWD", temp_env->name) == 0)
		{
			free(temp_env->content);
			temp_env->content = oldpwd;
			break ;
		}
		temp_env = temp_env->next;
	}
}

static void	change_env_pwd(t_mnsh *data)
{
	t_env	*temp_env;
	char	*temp_pwd;

	temp_env = data->env;
	temp_pwd = NULL;
	while (temp_env)
	{
		if (ft_strcmp("PWD", temp_env->name) == 0)
		{
			if (temp_env->content)
				temp_pwd = ft_strdup(temp_env->content);
			free(temp_env->content);
			temp_env->content = getcwd(NULL, 0);
			break ;
		}
		temp_env = temp_env->next;
	}
	change_env_oldpwd(data, temp_pwd);
	data->status = 0;
}

void	ft_cd(t_cmd *cmd, t_mnsh *data)
{
	if (cmd->len_argv >= 2)
	{
		if (cmd->argv[1][0] == '-' && cmd->argv[1][1])
			print_option_error(cmd->argv[1], data);
		else if (cmd->len_argv > 2)
		{
			ft_putendl_fd("bash: cd: too many arguments", 2);
			data->status = 1;
		}
		else
		{
			if (chdir(cmd->argv[1]) == -1)
				print_dir_error(cmd->argv[1], data);
			else
				change_env_pwd(data);
		}
	}
	else if (cmd->len_argv == 1)
	{
		data->status = 1;
		if (chdir(getenv("HOME")) == -1)
			ft_putendl_fd("bash: cd: HOME not set", 2);
		else
			change_env_pwd(data);
	}
}
