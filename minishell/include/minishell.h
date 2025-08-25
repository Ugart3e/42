/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:00 by anareval          #+#    #+#             */
/*   Updated: 2025/08/25 17:10:42 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>
# include <errno.h>
# include <string.h>

extern volatile sig_atomic_t	g_signal;

typedef struct s_tok
{
	struct s_tok	*next;
	char			*content;
	int				type;
}	t_tok;

typedef struct s_cmd
{
	char			**argv;
	int				len_argv;
	int				fdin;
	int				fdout;
	int				error;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef enum e_tok_type
{
	T_PIPE = 1,
	T_HEREDOC = 2,
	T_APPEND = 3,
	T_REDIRECTION_INFILE = 4,
	T_REDIRECTION_OUTFILE = 5,
	T_WORD = 6,
	T_SIMPLE_QUOTE = 7,
	T_DOUBLE_QUOTE = 8,
}	t_tok_type;

typedef struct s_mnsh
{
	t_cmd	*cmd;
	t_env	*env;
	t_env	*export;
	t_tok	*tok;
	int		len_cmds;
	int		*pids;
	char	**envp;
	int		status;
}	t_mnsh;

//builtin/**********************************************************************
//ft_cd.c-----------------------------------------------------------------------
//static void	print_dir_error(char *argv);
//static void	print_option_error(char *argv);
//static void	change_env_oldpwd(t_mnsh *data, char *oldpwd);
//static void	change_env_pwd(t_mnsh *data);
void	ft_cd(t_cmd *cmd, t_mnsh *data);

//ft_echo.c---------------------------------------------------------------------
//static	int	ft_isnoption(char *str);
void	ft_echo(t_cmd *cmd, t_mnsh *data);

//ft_env.c----------------------------------------------------------------------
t_env	*ft_envnew(char *name, char *content);
void	ft_envadd_back(t_env **env, t_env *new);
void	ft_env(t_env *env, t_cmd *cmd);
void	init_env(t_env **env, char **envp);
void	env_generator(t_mnsh *data);

//ft_exit.c---------------------------------------------------------------------
//static int	ft_isnumber(char *nbr);
//static int	ft_isoverflow(char *str);
//static void	ft_exit_free(t_mnsh *data, int exitnbr);
void	ft_exit(t_cmd *cmd, t_mnsh *data);

//ft_export_argv.c--------------------------------------------------------------
//static int	is_env(char *name, t_env *env);
//static void	ft_change_content_env(t_env *env, char *name, char *content);
//static void	ft_addenv(t_mnsh *data, char *name, char *content);
void	ft_export_arg(t_mnsh *data, char *name, char *content, char *arg);

//ft_export_utils.c-------------------------------------------------------------
void	export_invalid_option_msg(t_mnsh *data, char *arg);
void	export_invalid_identifier_msg(t_mnsh *data, char *arg);
void	ft_swap(char **a, char **b);

//ft_export.c-------------------------------------------------------------------
//static int	is_shorted(t_env *env);
//static void	ft_short_export(t_env *export);
//static void	ft_print_export(t_mnsh *data);
//static int	ft_process_export_arg(t_cmd *cmd, t_mnsh *data, int argv);
void	ft_export(t_cmd *cmd, t_mnsh *data);

//ft_pwd.c----------------------------------------------------------------------
void	ft_pwd(t_cmd *cmd, t_mnsh *data);

//ft_unset.c-------------------------------------------------------------------
//static void	ft_rm_env(t_env **lst, char *name)
void	ft_unset(t_cmd *cmd, t_mnsh *data);

//executor/*********************************************************************
//executor_utils.c--------------------------------------------------------------
void	calculate_cmd_len(t_mnsh *data);
void	ft_redir_pipes(t_mnsh *msh, t_cmd *cmd, int i);
int		redir_in_out(t_cmd *cmd);
void	execution_cleaner(t_mnsh *data, int saved_stdin, int saved_stdout);

//executor_utils2.c-------------------------------------------------------------
void	execute_one_cmd_process(t_mnsh *data, char *cmd);
void	execute_multi_cmd_process(t_mnsh *data, t_cmd *cmd);

//ft_executor.c-----------------------------------------------------------------
//static void	execute_process_multi_cmd(t_mnsh *data, t_cmd *cmd, int i);
int		is_builtin(t_cmd *cmd, t_mnsh *mnsh);
void	execute_multi_cmd(t_mnsh	*data, t_cmd *cmd, int i);
void	execute_one_cmd(t_mnsh	*data);
void	execute_process(t_mnsh *data);

//path_utils.c------------------------------------------------------------------
//static char	*ft_checkaccess(char **path, char *cmd);
void	ft_failpath(char **cmd2, char *path);
char	*get_path(char **env, char *cmd);

//parser/***********************************************************************
//expand_variables_utils.c------------------------------------------------------
char	*handle_invalid_dollar(char *str, char *result, int *i);
char	*expand_variables_in_string_loop(char *str, char *result, t_mnsh *data);
char	*expand_variables_in_string(char *str, t_mnsh *data);
char	*handle_exit_status_case(char *word, t_mnsh *data);

//expand_variables.c------------------------------------------------------------
//static int	find_var_end(char *str, int start);
//static char	*get_expanded_value(char *str, int start, int end, t_mnsh *data)
//static char	*handle_normal_variable(char *word, t_mnsh *data, int i)
char	*process_variable(char **str_ptr, char *reslt, t_mnsh *data, int *i);
char	*expand_if_variable(char *word, t_mnsh *data);

//parse_redirection.c-----------------------------------------------------------
//static void	handle_infile(t_cmd *cmd, char *filename);
//static void	handle_outfile(t_cmd *cmd, char *filename);
//static void	handle_append(t_cmd *cmd, char *filename)
int		handle_redirection(t_cmd *cmd, t_tok **token);

//parse_tokens.c----------------------------------------------------------------
//static t_cmd	*start_new_cmd(t_cmd **cmds, t_cmd **last_cmd);
//static void	handle_word_token(t_cmd **current_cmd, t_tok *token,
		//t_cmd **cmds, t_cmd **last_cmd)
//static int	handle_redir_token(t_cmd *current_cmd, t_tok **token);
//static void	process_token(t_tok **current_token, t_cmd **current_cmd,
		//t_cmd **cmds, t_cmd **last_cmd)
t_cmd	*parse_tokens(t_tok *tokens);

//parse_utils.c-----------------------------------------------------------------
//static char	*generate_temp_filename(void);
//static int	process_heredoc_content(char *delimiter, char *temp_file);
int		is_redirection_token(int type);
int		validate_syntax(t_tok *tokens);
int		handle_heredoc(t_cmd *cmd, char *delimiter);

// parse_utils_utils.c----------------------------------------------------------
int		starts_with_pipe(t_tok *tokens);
int		is_syntax_error_at(t_tok *current);
void	put_heredoc_prompt(void);
int		heredoc_loop(char *delimiter, int fd);

//parser.c----------------------------------------------------------------------
t_cmd	*create_cmd(void);
int		add_arg_to_cmd(t_cmd *cmd, char *arg);
int		parse_input(char *input, t_mnsh *data);

//tokenize_utils.c--------------------------------------------------------------
t_tok	*create_token(char *content, int type);
void	add_token(t_tok **tokens, t_tok *new);
int		is_special_char(char c);
char	*expand_env_variable(char *var_name, t_env *env);
char	*extract_quoted_content(char **input, char quote_char);

//tokenize_utils2.c-------------------------------------------------------------
char	*process_quoted_content(char **input,
			char *complete_word, t_mnsh *data);
char	*process_unquoted_content(char **input,
			char *complete_word, t_mnsh *data);

//tokenizer.c-------------------------------------------------------------------
//static void	process_special_token(char **input, t_tok **tokens);
//static void	process_word(char **input, t_tok **tokens, t_env *env);
//static void	skip_spaces(char **input);
t_tok	*tokenize(char *input, t_mnsh *data);

//utils/************************************************************************
//ft_free.c---------------------------------------------------------------------
void	ft_free_tokens(t_tok **tokens);
void	ft_free_cmds(t_cmd **cmds);
void	ft_free_env(t_env **env);
void	ft_freemnsh(t_mnsh *data);

//ft_free2.c--------------------------------------------------------------------
void	ft_free_name_content(char *name, char *content);
void	ft_free_node(t_env *node);
void	ft_free_ptrptr(char ***ptr);
void	ft_close_free_execut(t_mnsh *data, int saved_stdin, int saved_stdout);

//ft_signals.c------------------------------------------------------------------
//static void	handle_signal(int signo);
void	init_signals(void);

//minisell.c--------------------------------------------------------------------
//static void	ini_data(t_mnsh *data);
//int	main(void);

#endif
