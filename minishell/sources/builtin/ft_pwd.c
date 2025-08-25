/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:23 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:24 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_cmd *cmd, t_mnsh *data)
{
	char	*cwd;

	if (cmd->argv[1] && cmd->argv[1][0] == '-' && cmd->argv[1][1]
		&& cmd->argv[1][1] != '-')
	{
		ft_putstr_fd("bash: pwd: ", 2);
		ft_putchar_fd(cmd->argv[1][1], 2);
		ft_putendl_fd(": invalid option", 2);
		data->status = 2;
		return ;
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_putendl_fd("Error.", 2);
		data->status = 1;
		return ;
	}
	printf("%s\n", cwd);
	data->status = 0;
	free(cwd);
}
