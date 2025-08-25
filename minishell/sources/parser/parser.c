/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:27:10 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:12 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*create_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->argv = NULL;
	new->len_argv = 0;
	new->fdin = -1;
	new->fdout = -1;
	new->error = 0;
	new->next = NULL;
	return (new);
}

int	add_arg_to_cmd(t_cmd *cmd, char *arg)
{
	char	**new_argv;
	int		i;

	i = 0;
	new_argv = (char **)malloc(sizeof(char *) * (cmd->len_argv + 2));
	if (!new_argv)
		return (0);
	while (i < cmd->len_argv)
	{
		new_argv[i] = cmd->argv[i];
		i++;
	}
	new_argv[i] = ft_strdup(arg);
	new_argv[i + 1] = NULL;
	free(cmd->argv);
	cmd->argv = new_argv;
	cmd->len_argv++;
	return (1);
}

int	parse_input(char *input, t_mnsh *data)
{
	data->tok = tokenize(input, data);
	if (!data->tok)
		return (0);
	if (!validate_syntax(data->tok))
	{
		ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
		ft_free_tokens(&data->tok);
		return (0);
	}
	data->cmd = parse_tokens(data->tok);
	if (!data->cmd)
	{
		ft_free_tokens(&data->tok);
		return (0);
	}
	return (1);
}
