/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:27:23 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:25 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tokens(t_tok **tokens)
{
	t_tok	*tmp;
	t_tok	*next;

	if (!tokens || !*tokens)
		return ;
	tmp = *tokens;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*tokens = NULL;
}

void	ft_free_cmds(t_cmd **cmds)
{
	t_cmd	*tmp;
	t_cmd	*next;
	int		i;

	if (!cmds || !*cmds)
		return ;
	tmp = *cmds;
	while (tmp)
	{
		next = tmp->next;
		i = 0;
		while (tmp->argv && tmp->argv[i])
			free(tmp->argv[i++]);
		free(tmp->argv);
		if (tmp->fdin != STDIN_FILENO && tmp->fdin != -1)
			close(tmp->fdin);
		if (tmp->fdout != STDOUT_FILENO && tmp->fdout != -1)
			close(tmp->fdout);
		free(tmp);
		tmp = next;
	}
	*cmds = NULL;
}

void	ft_free_env(t_env **env)
{
	t_env	*temp_env;

	while (*env)
	{
		free((*env)->name);
		free((*env)->content);
		temp_env = (*env)->next;
		free(*env);
		*env = temp_env;
	}
	*env = NULL;
}

void	ft_freemnsh(t_mnsh *data)
{
	if (data->env)
		ft_free_env(&data->env);
	if (data->export)
		ft_free_env(&data->export);
	if (data->envp)
		ft_free_ptrptr(&data->envp);
	if (data->cmd)
		ft_free_cmds(&data->cmd);
	if (data->tok)
		ft_free_tokens(&data->tok);
	if (data->pids)
	{
		free(data->pids);
		data->pids = NULL;
	}
}
