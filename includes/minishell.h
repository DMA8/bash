/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:33:59 by arashido          #+#    #+#             */
/*   Updated: 2023/11/23 17:29:51 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

# define SYMBOLS "|><"
# define SPACES " \t\r\n\f\v"
# define QUOTES "\'\""

typedef struct s_quotes
{
	bool					is_single;
	bool					is_double;
}							t_quotes;

typedef enum s_redir_type // type of redirection
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
}							t_redir_type;

typedef enum c_cmdtype
{
	WORD,
	REDIR,
	PIPE,
}							t_cmdtype;

typedef struct s_token
{
	// word command or redirection
	t_cmdtype				type;
	// str for word or redirection
	char					*arg;
	struct s_token			*next;
}							t_token;

typedef struct s_redirections
{
	// type of redirection: INPUT, OUTPUT, APPEND, HEREDOC
	t_redir_type			type;
	// file name for redirection or delimeter for heredoc allocated by strdup
	int						fd;
	// file descriptor for redirection
	char					*file;
	struct s_redirections	*next;
}							t_redirections;

typedef struct s_command
{
	// linked list for redirections
	t_redirections			*redirections;
	// cmd name allocated by strdup
	char					*cmd;
	// execve for example: {"/bin/ls", "-l", NULL}; allocated by strdup
	char					**args;
	// total redirections
	int						total_redirs;
	// total arguments
	int						total_args;
}							t_command;

typedef struct s_minishell
{
	t_command				**commands;
}							t_minishell;

/****************** PARSING ********************/

// global var
extern int					g_error_status;

// parsing -> expansion
bool						needs_expansion(char *str);
t_token						*new_token_node(char *arg);
t_token						*create_token_list(char **tokens);
void						add_token_node(t_token **tokenlist,
								t_token *tokenNode);
void						expand_token(t_token **tokenlist, char *str);

// parsing -> expansion_helpers
char						*strjoin_new_var(char *temp_str, char *expanded_str,
								int count);
int							get_end_index_expan(char *str, int start);
int							get_search_var_end(char *str, int start);

// parsing -> syntax_check
bool						token_syntax_check(t_token *headtoken);
void						token_quote_removal(t_token *tokenlist);
// parsing -> strtok
char						**ft_space(char *s);
char						**ft_strtok(char *s);
bool						find_char(char *s, char c);
bool						check_unmatched_quotes(char *str);
void						set_quote_flag(t_quotes *value, char c);
int							get_end_index(char *s, char *delimiters, int start);

// parsing -> rediraction
int							count_pipes(t_token *start);
t_command					**create_commands(t_token *start);

void						fill_redirs(t_command *scommand, t_token *redir,
								t_token *file);
void						fill_scmnd(t_command *scommand, t_token *start,
								t_token *end);

// parsing -> utils
char						**dup_array(char **src);
int							ft_array_len(char **str);
bool						find_char(char *s, char c);
char						**ft_join(char **s1, char **s2);
int							ft_strcmp(const char *s1, const char *s2);

// parsing -> parse.c
void						parse(char *line);
char						**ft_delimiter(char *str);
t_token						*ft_tokenise(char **str_tokens);

// parsing -> free.c
void						free_array(char **array);
void						safe_free(void *ptr);

// debugging functions
void						print_tokenlist(t_token *tokenlist);
void						print_array(char **array, char *name);
void						print_commands(t_command **array_of_commands);

#endif