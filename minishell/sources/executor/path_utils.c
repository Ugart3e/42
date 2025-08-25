/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:42 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:25:43 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_checkaccess(char **path, char *cmd)
{
	int		j;
	char	*cmd2;
	char	*tmp;
	char	*tmp2;

	j = 0;
	cmd2 = NULL;
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (path[++j])
	{
		tmp = ft_strjoin(path[j], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		if (access(tmp2, X_OK) == 0)
		{
			free(cmd2);
			cmd2 = ft_strdup(tmp2);
			free(tmp);
			free(tmp2);
			break ;
		}
		free(tmp);
		free(tmp2);
	}
	return (cmd2);
}

void	ft_failpath(char **cmd2, char *path)
{
	ft_putstr_fd(cmd2[0], 2);
	ft_putendl_fd(": command not found", 2);
	free(path);
}

char	*get_path(char **env, char *cmd)
{
	int		i;
	char	**path;
	char	*cmd2;

	i = 0;
	cmd2 = NULL;
	if (!env || env[0] == NULL)
	{
		path = ft_split("/bin:/usr/bin", ':');
		cmd2 = ft_checkaccess(path, cmd);
		ft_free_ptrptr(&path);
		return (cmd2);
	}
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			cmd2 = ft_checkaccess(path, cmd);
			ft_free_ptrptr(&path);
			break ;
		}
		i++;
	}
	return (cmd2);
}
