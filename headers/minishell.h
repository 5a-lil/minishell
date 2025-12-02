/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:23:14 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 17:21:16 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

/* DEFINES */

# define PATH_MAX 260
# define TRUE 1
# define FALSE 0
# define INFILE 0
# define OUTFILE 1
# define HEREDOC 2
# define OUTFILE_APPEND 11
# define LIMIT_MIN -65536
# define LIMIT_MAX 65535

/* ERRCODE */

# define TO_MANY_ARGS_ERRCODE 1
# define ERROR 1
# define CTRLC_ERRCODE 130

# include "../libft/libft.h"
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

extern int	g_sig;

typedef struct s_data
{
	char	previous_cwd[PATH_MAX];
	int		child_exit_code;
	size_t	exit_code;
	int		stds[2];
	int		stdin_copy;
	char	**envp;
	char	*prompt;
	t_list	*env_vars;
	int		end_tty;
}			t_data;

/* minishell.c */
t_list		*init_lists(char **to_tokenize);

////////////////////////////// PARSING //////////////////////////////////////

/* env_expansion.c */
char		*env_expansion(t_data *data, char *str);
void		handle_dollar_sign(t_data *data, const char *str, char **result,
				int *i);
void		handle_single_quotes(const char *str, char **result, int *i);
char		*strjoin_char(char *str, char c);
/* mini_env_expansion.c */
void		mini_env_expansion_double_quotes(t_data *data, const char *str,
				char **result, int *i);
void		mini_env_expansion(t_data *data, const char *str, char **result,
				int *i);
/* recursive_descent_parsing.c */
int			prompt_parsing(char *line, t_data *data);
void		print_list(t_list *list);
/* processes.c */
int			is_heredoc(t_list *cmd_l);
void		fork_child_process(char *cmd, t_data *data);
/* last_cmd_process.c */
void		last_cmd_child_process(char *cmd, t_data *data);
void		close_files(int fds[2]);
/* signals.c */
void		ctrl_c_display(int i);
void		ctrl_c_no_display(int i);
void		ctrl_c_heredoc(int i);
/* exec_builtins.c */
char		*my_strchr(const char *s, int c);
char		*find_valid_path(t_list *env_vars, char **cmd);
void		exec_builtins(char *temp_cmd, t_list *env_vars, t_data *data);
/* exec.c */
void		exec_cmd(char *cmd, t_list *env_vars, t_data *data);
/* list_inits.c */
int			strlen_till_not_char(const char *str, const char *charset);
t_list		*init_prompt_list(const char *prompt);
/* list_inits_handle.c */
void		handle_double_quotes_list(const char *prompt, char **temp, int *i);
void		handle_single_quotes_list(const char *prompt, char **temp, int *i);
void		handle_non_quotes_list(const char *prompt, char **temp, int *i);
void		handle_special_chars(const char *prompt, char **temp, int *i,
				t_list **result);
/* list_wredir_inits.c */
t_list		*init_without_redir_list(const char *prompt);
/* list_wredir_inits_handle.c */
void		handle_non_quotes_without_redir(const char *prompt, char **temp,
				int *i);
void		handle_double_quotes_without_redir(const char *prompt, char **temp,
				int *i);
void		handle_single_quotes_without_redir(const char *prompt, char **temp,
				int *i);

/* checks.c */
int			check_syntax(const char *prompt);
/* checks_list */
void		check_list(t_list *list, t_list *env_vars, t_data *data);
/* checks_quotes */
int			check_quotes_and_pipes(const char *prompt, t_list **cmd_l);
/* redirs.c */
int			open_file(char *file, int i);
void		redir(t_list *curr, int temp_fds[2], t_data *data);
/* mini_redirs.c */
void		mini_handle_output_redir(t_list **curr, int temp_fds[2]);
void		mini_handle_input_redir(t_list **curr, int temp_fds[2],
				t_data *data);
/* redirs_handle.c */
void		handle_heredoc_input(t_data *data, char *limiter, int fd);
void		heredoc(t_data *data, char *limiter);
void		handle_output_redir(t_list **curr, int *temp_fds, int append,
				int (*f)(char *, int));
void		handle_input_redir(t_list **curr, int *temp_fds, int (*f)(char *,
					int));

//////////////////////////////// UTILS //////////////////////////////////////

/* split_quote.c */
char		**split_quote(char *s, char c);
/* split_quote_loop. c */
void		skip_loop(char **s, char c);
void		assert_loop_39(char **result, char **s, int k, int *i);
/* split_ign_quote.c */
char		**split_ign_quote(char const *s, char c);
/* mini_split_ign_quotes.c */
void		handle_single_quote_split(const char **s, char *result, size_t *i);
void		handle_double_quote_split(const char **s, char *result, size_t *i);
void		handle_non_quote_split(const char **s, char *result, size_t *i,
				char c);
/* exit_free.c */
void		exit_free(t_list *tokens, t_list *env_vars, int err_code);
void		free_data(t_data *data);
/* find_env_var.c */
t_list		*find_env_var(t_list *env_vars, char *var_name);
/* temp_func.c */
void		print_tokens(t_list *tokens);
/* list_to_table.c */
char		**list_to_table(t_list *list);
/* print_alph_sorted.c */
void		swap_table(char **a, char **b);
int			ft_strcmp(const char *a, const char *b);
void		print_export_list(int argc, char **argv);
/* strdup_quote.c */
char		*strdup_quote(const char *source);
/* table_to_string.c */
char		*table_to_string(char **table);

///////////////////////////// BUILTINS /////////////////////////////////////

/* echo.c */
void		echo(t_list **tokens);
void		dash_n_flag(t_list **tokens);
int			is_dash_n_flag(char *token);
/* cd.c */
int			cd(t_list **tokens, t_data *data, t_list *env_vars);
/* pwd.c */
int			pwd(t_list **tokens);
/* exit.c */
void		exit_bash(t_list **tokens, t_data *data);
/* export.c */
void		export(t_list **tokens, t_list *env_vars, t_data *data);
void		print_env_export(t_list *env_vars);
/* env.c */
void		env(t_list **tokens, t_list *env_vars);
/* unset.c */
void		unset(t_list **tokens, t_list *env_vars);
/* utils_builtins/is_builtin.c */
int			is_builtin(const char *cmd);
/* utils_builtins/openf_builtins.c */
void		redir_builtins(t_data *data, t_list *curr, int temp_fds[2]);

//////////////////////////// BASH_FEATURES /////////////////////////////////

/* is_dir.c */
void		is_dir(t_list **tokens, t_data *data);
/* is_executable.c */
int			file_exists(const char *file);
int			is_executable(const char *path);

#endif