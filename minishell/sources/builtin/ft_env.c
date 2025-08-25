/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:24:36 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:24:37 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_envnew(char *name, char *content)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->name = ft_strdup(name);
	if (content)
		env->content = ft_strdup(content);
	else
		env->content = NULL;
	env->next = NULL;
	return (env);
}

void	ft_envadd_back(t_env **env, t_env *new)
{
	t_env	*temp;

	if (!*env)
	{
		*env = new;
		return ;
	}
	temp = *env;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_env(t_env *env, t_cmd *cmd)
{
	t_env	*temp;

	if (cmd->len_argv > 1)
	{
		if (cmd->argv[1] && cmd->argv[1][0] == '-')
			printf("env: invalid option -- «%c»\n", cmd->argv[1][1]);
		else
			printf("env: «%s»:  No such file or directory\n", cmd->argv[1]);
		return ;
	}
	temp = env;
	while (temp)
	{
		printf("%s=%s\n", temp->name, temp->content);
		temp = temp->next;
	}
}

void	init_env(t_env **env, char **envp)
{
	int		i;
	int		len;
	char	*content;
	char	*name;

	i = 0;
	if (!envp[i])
		return ;
	while (envp[i])
	{
		len = 0;
		while (envp[i] && envp[i][len] != '=')
			len++;
		name = ft_substr(envp[i], 0, len);
		if (ft_strchr(envp[i], '='))
			content = ft_strdup(ft_strchr(envp[i], '=') + 1);
		else
			content = NULL;
		if (!*env)
			*env = ft_envnew(name, content);
		else
			ft_envadd_back(env, ft_envnew(name, content));
		ft_free_name_content(name, content);
		i++;
	}
}

void	env_generator(t_mnsh *data)
{
	t_env	*temp;
	int		i;
	char	*str_temp;

	i = 0;
	temp = data->env;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	data->envp = malloc(sizeof(char *) * (i + 1));
	temp = data->env;
	i = 0;
	while (temp)
	{
		str_temp = ft_strjoin(temp->name, "=");
		if (temp->content)
			data->envp[i++] = ft_strjoin(str_temp, temp->content);
		else
			data->envp[i++] = ft_strdup(str_temp);
		free(str_temp);
		temp = temp->next;
	}
	data->envp[i] = NULL;
}
