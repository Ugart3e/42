/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:30 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:31 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_rm_env(t_env **lst, char *name)
{
	t_env	*temp_lst;
	t_env	*previus_node;

	temp_lst = *lst;
	previus_node = NULL;
	if (!name)
		return ;
	while (temp_lst)
	{
		if (ft_strcmp(name, temp_lst->name) == 0)
		{
			if (!previus_node)
				*lst = temp_lst->next;
			else
				previus_node->next = temp_lst->next;
			ft_free_node(temp_lst);
			break ;
		}
		previus_node = temp_lst;
		temp_lst = temp_lst->next;
	}
}

void	ft_unset(t_cmd *cmd, t_mnsh *data)
{
	int	i;

	i = 1;
	if (cmd->argv[1] && cmd->argv[1][0] == '-' && cmd->argv[1][1]
		&& cmd->argv[1][1] != '-')
	{
		ft_putstr_fd("bash: unset: ", 2);
		ft_putchar_fd(cmd->argv[1][1], 2);
		ft_putendl_fd(": invalid option", 2);
		data->status = 2;
		return ;
	}
	while (cmd->argv[i])
	{
		ft_rm_env(&data->env, cmd->argv[i]);
		ft_rm_env(&data->export, cmd->argv[i]);
		i++;
	}
	data->status = 0;
}
