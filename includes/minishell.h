/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:35:09 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/20 18:17:28 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "structures.h"
# include "builtins.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>

extern int g_last_exit_status;
extern t_env *g_env;

// lexer
t_token         *tokenize(char *line);

// token_create
t_token         *create_token(char *value, t_token_type type); // creation d'un token
void            add_token_list(t_token **head, t_token *new_token); // ajoute un token a la liste chainee
t_token_type    token_id(char *value); // definie l'id du token
int             get_space_after(char *line, int pos); // check si il y a un espace
t_token         *find_last_token(t_token *head); // trouver le dernier token de la liste chainee4

// lexer utils
int             is_whitespace(char c);
int             is_operator_char(char c);
int             is_quote(char c);
void            skip_whitespace(char *line, int *index);
int 			is_special_char(char c);

// quote
int             handle_quotes_in_word(char *line, int start, t_token **head); // process pour les quotes
t_quote_state   get_quote_type(char c); // savoir quelle type de quote
int             is_quote_closed(char *line, int start, char quote_char); // quote ferme ou non

// expand_manager.c
void    		expand_tokens(t_token *tokens, t_env *env, int last_exit_status);

// expand_quotes.c
void    		remove_quotes(char **str); // remove quote
int     		is_single_quoted(char *str); // detecte si simple quote
int     		is_double_quoted(char *str); // detecte si double quote
char    		*extract_quoted_content(char *str); // extrait le content des quotes
void    		process_quotes_in_token(t_token *token); // applique les quotes sur le token

// expand_vars.c
void    		expand_variables(char **str, t_env *env, int last_exit_status); // remplace les var
char    		*get_var_name(char *str, int start); // nom var
char    		*get_var_value(char *var_name, t_env *env, int last_exit_status); // return var value
int     		find_next_dollar(char *str, int start); // chercher $
char    		*build_expanded_str(char *str, int var_pos, char *var_name, char *value); // rebuilt la string avec la valeur de la var

// expand_utils.c
int     		should_expand_token(t_token *token); // tchecksi expand ou non
void    		remove_empty_tokens(t_token **head); // delete token
int     		is_expandable_char(char c); // tcheck si char = var ou non
int     		count_varname_len(char *str); // calcule la longeur du nom de la var

// expand_split.c
void    		split_expanded_tokens(t_token **head); // split token avec espace
int     		contains_whitespace(char *str); // tcheck espce
void    		replace_token_with_split(t_token **head, t_token *token, char **words); // decoupe ls tring
char    		**split_by_whitespace(char *str);
void    		free_split(char **split);

// syntax_checker.c
int     		check_syntax(t_token *tokens);
int     		has_syntax_error(t_token *tokens);

// syntax_pipe.c
int     		check_pipe_errors(t_token *tokens);
int     		is_pipe_at_start(t_token *tokens);
int     		is_pipe_at_end(t_token *tokens);
int     		has_empty_pipe(t_token *tokens);
int     		has_consecutive_pipes(t_token *tokens);

// syntax_redir.c
int     		check_redir_errors(t_token *tokens);
int     		is_redir_without_file(t_token *token);
int     		has_consecutive_redirs(t_token *tokens);
int     		is_valid_redir_target(t_token *token);
int     		check_heredoc_delimiter(t_token *token);

// syntax_utils.c
int     		is_redirection(t_token_type type);
int     		is_operator(t_token_type type);
void    		skip_whitespace_tokens(t_token **token);
t_token 		*get_next_meaningful_token(t_token *token);
int     		is_empty_command(t_token *start, t_token *end);

// syntax_error.c
void    		print_syntax_error(char *token);
void    		print_unexpected_token_error(char *token);
void    		print_unexpected_newline_error(void);
void    		print_unclosed_quote_error(void);
int     		set_syntax_error(char *near_token);

// fonction utils
void 			free_array(char **array); // free un tableau
void 			free_env_list(t_env *env); // free env liste chainés
void 			free_token_list(t_token *head); // free token liste chainés

// fonction cas d'erreur
void			print_history(void);
void			prompt(void);

// parser.c
t_cmd   		*parse_tokens(t_token *tokens);
void    		free_cmd_list(t_cmd *cmd);

// cmd_builder.c
t_cmd   		*create_cmd(void);
void    		add_argument(t_cmd *cmd, char *arg);
void    		finalize_cmd_args(t_cmd *cmd);
void    		link_commands(t_cmd *cmd1, t_cmd *cmd2);
void    		free_cmd(t_cmd *cmd);

// redir_parser.c
t_redir 		*create_redir(t_token_type type, char *file);
void    		add_redir_to_cmd(t_cmd *cmd, t_redir *redir);
int     		parse_redirection(t_cmd *cmd, t_token **current);
void    		free_redir_list(t_redir *redirs);
int     		is_redir_token(t_token_type type);

// parser_utils.c
int     		count_cmd_args(t_cmd *cmd);
int     		is_end_of_cmd(t_token *token);
t_token 		*skip_to_next_cmd(t_token *token);
char    		**create_args_array(int size);

// arg_collector.c
int     		collect_arguments(t_cmd *cmd, t_token **tokens);
int     		should_collect_arg(t_token *token);
int     		process_word_token(t_cmd *cmd, t_token *token);
void    		advance_token(t_token **tokens);
int     		is_delimiter(t_token *token);

// executor.c
int     		execute_commands(t_cmd *cmd, t_env *env);
int     		execute_single_command(t_cmd *cmd, t_env *env);
int     		execute_pipeline(t_cmd *cmd, t_env *env);
int     		count_commands(t_cmd *cmd);
void    		update_exit_status(int status);

// exec_cmd.c
int     		execute_simple_cmd(t_cmd *cmd, t_env *env);
int     		save_std_fds(int *saved_stdin, int *saved_stdout);
void    		restore_std_fds(int saved_stdin, int saved_stdout);
int     		should_fork_builtin(char *cmd_name);
int     		handle_empty_command(t_cmd *cmd);

// exec_builtin.c
int     		is_builtin(char *cmd_name);
int     		execute_builtin(char **args, t_env *env);
int     		execute_builtin_fork(char **args, t_env *env);
void    		exit_builtin_child(int status);
int     		get_builtin_index(char *cmd_name);

// exec_external.c
int     		execute_external(t_cmd *cmd, t_env *env);
void    		execute_external_child(t_cmd *cmd, t_env *env);
char    		**env_to_array(t_env *env);
void    		handle_execve_error(char *cmd);
void    		free_env_array(char **env_array);

// exec_pipes.c
int     		**create_pipes(int count);
void    		close_all_pipes(int **pipes, int count);
void    		free_pipes(int **pipes, int count);
void    		setup_pipe_child(int **pipes, int cmd_index, int total_cmds);
int     		execute_pipe_cmd(t_cmd *cmd, t_env *env, int **pipes, int index);

// redirections.c
int     		apply_redirections(t_redir *redirs);
int     		open_redirect_file(t_redir *redir);
int     		redirect_input(char *file);
int     		redirect_output(char *file, int append);
void    		close_redirect_fds(t_redir *redirs);

// heredoc.c
int     		handle_heredoc(char *delimiter);
int     		read_heredoc_input(char *delimiter);
void    		write_heredoc_line(int fd, char *line);
int     		should_stop_heredoc(char *line, char *delimiter);
void    		cleanup_heredoc(int fd, char *temp_file);

// path_finder.c
char    		*find_command_path(char *cmd, t_env *env);
char    		*get_env_path(t_env *env);
char    		**split_path(char *path);
char    		*check_path_access(char *cmd, char **paths);
int     		is_absolute_path(char *cmd);

// signals.c
void    		setup_signals(void);
void    		setup_child_signals(void);
void    		handle_sigint(int sig);
void    		handle_sigquit(int sig);
void    		ignore_signals(void);

// wait_process.c
int     		wait_single_child(pid_t pid);
int     		wait_all_children(pid_t *pids, int count);
int     		get_exit_status(int status);
void    		handle_signal_status(int status);
int     		wait_last_child(pid_t *pids, int count);

void rl_replace_line(const char *text, int clear_undo);

#endif
