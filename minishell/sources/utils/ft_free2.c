/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:27:28 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:29 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_name_content(char *name, char *content)
{
	free(name);
	if (content)
		free(content);
}

void	ft_free_node(t_env *node)
{
	free(node->name);
	free(node->content);
	free(node);
}

void	ft_free_ptrptr(char ***ptr)
{
	int		i;
	char	**tmp;

	if (!ptr || !*ptr)
		return ;
	tmp = *ptr;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	*ptr = NULL;
}

void	ft_close_free_execut(t_mnsh *data, int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
	if (data->pids)
	{
		free(data->pids);
		data->pids = NULL;
	}
	if (data->cmd)
		ft_free_cmds(&data->cmd);
	if (data->tok)
		ft_free_tokens(&data->tok);
	if (data->envp)
		ft_free_ptrptr(&data->envp);
}
