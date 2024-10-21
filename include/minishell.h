/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 13:13:42 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ----------------------------------------
// Includes
// ----------------------------------------

# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/statfs.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

// ----------------------------------------
// Definitions
// ----------------------------------------

# ifndef MS_PROMPT
#  define MS_PROMPT "ツ > "
# endif

// ----------------------------------------
// Enums
// ----------------------------------------

enum					e_ExitCode
{
	MS_EXIT_SUCCESS = 0,
	MS_EXIT_MALLOC_ERROR,
	MS_EXIT_ASSERT_FAILED
};

typedef enum e_TokenType
{
	TKN_UNKNOWN,
	TKN_CMD,
	TKN_ARG,
	TKN_FILE,
	TKN_PIPE,
	TKN_REDIRECT_IN_DELIM,
	TKN_REDIRECT_IN,
	TKN_REDIRECT_OUT,
	TKN_REDIRECT_OUT_APPEND,
	TKN_END
}						t_token_type;

enum					e_BuiltIn
{
	BI_UNKNOWN,
	BI_ECHO,
	BI_CD,
	BI_PWD,
	BI_EXPORT,
	BI_UNSET,
	BI_ENV,
	BI_EXIT,
};

enum					e_TknParseState
{
	TKN_PS_EMPTY,
	TKN_PS_WORD
};

enum					e_TknParseSymbolType
{
	TKN_PS_SYMBOL_WHITESPACE,
	TKN_PS_SYMBOL_LETTER,
	TKN_PS_SYMBOL_PIPE,
	TKN_PS_SYMBOL_NULL_TERMINATOR
};

// ----------------------------------------
// Structures
// ----------------------------------------

typedef struct s_token
{
	enum e_TokenType	type;
	char				*value;
	struct s_token		*next;
}						t_token;

typedef struct s_token_list
{
	struct s_token		*head;
	struct s_token		*tail;
}						t_token_list;

typedef struct s_env_var
{
	char				*key;
	char				*value;
	struct s_env_var	*next;
}						t_env_var;

typedef struct s_env_var_list
{
	struct s_env_var	*head;
	struct s_env_var	*tail;
}						t_env_var_list;

// ----------------------------------------
// Functions
// ----------------------------------------

// Utils

char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
size_t					ft_strlen(const char *s);
char					*ft_strndup(const char *s, ssize_t n);
void					*ms_malloc(size_t size);
void					ms_assert(bool predicate, const char *message);
char					*ft_strdup(const char *s);

// Signals

void					handle_sigint(int sig);
void					listen_sigint(void);

// Env

void					print_envp(const char **envp);
t_env_var_list			parse_envp(const char **envp);
void					print_env_var(t_env_var *var);
void					add_env_var(t_env_var_list *list, t_env_var *var);
void					init_env_var_list(t_env_var_list *list);
void					print_env_var_list(const t_env_var_list *list);
t_env_var				*create_env_var(const char *key, const char *value);
t_env_var				*get_env_var(t_env_var_list *list, const char *key);

// Tokens

void					tkn_add_token_to_list(t_token_list *token_list,
							t_token *token);
void					tkn_init_token_list(t_token_list *tokens);
t_token					*tkn_create_str(t_token_type type, char *s);
t_token					*tkn_create_substr(t_token_type type, char *s,
							ssize_t length);
t_token_list			parse_tokens(char *line);
void					print_token(t_token *token);
void					print_tokens(t_token_list *tokens);
char					*get_token_type_name(enum e_TokenType type);
void					free_token(t_token *token);
void					free_tokens(t_token_list *token_list);

// Exec

void					exec_builtin(t_token *token);
void					exec_echo(t_token *token);
void					exec_cd(t_token *token);
void					exec_pwd(t_token *token);
void					exec_exit(t_token *token);
void					exec_export(t_token *token);
void					exec_unset(t_token *token);
void					exec_env(t_token *token);
void					exec(t_token_list *tokens, t_env_var_list *env_vars);
void					exec_external(t_token *token);

// Builtins

bool					is_builtin(t_token *token);
void					assert_is_builtin(t_token *token);
enum e_BuiltIn			get_builtin(t_token *token);

#endif
