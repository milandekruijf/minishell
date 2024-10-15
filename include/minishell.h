/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:40:32 by mde-krui      ########   odam.nl         */
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

# ifndef PROMPT
#  define PROMPT "ツ > "
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

enum					e_TokenType
{
	TKN_UNKNOWN,

	TKN_CMD,
	TKN_ARG,
	TKN_FILE,
	TKN_PIPE,
	TKN_REDIRECT_IN_DELIM,
	TKN_REDIRECT_IN,
	TKN_REDIRECT_OUT,
	TKN_REDIRECT_OUT_APPEND
};

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

// ----------------------------------------
// Structures
// ----------------------------------------

typedef struct s_token
{
	enum e_TokenType	type;
	char				*value;
	struct s_token		*next;
}						t_token;

// ----------------------------------------
// Functions
// ----------------------------------------

// Utilities

int						ft_strcmp(const char *s1, const char *s2);
char					**ft_strsplit(char const *s, char c);
size_t					ft_strlen(const char *s);
void					*ms_malloc(size_t size);
void					ms_assert(bool predicate, char *message);

// Core

bool					is_builtin(t_token *token);
t_token					*get_last_token(t_token *tokens);
t_token					*create_token(enum e_TokenType, char *value);
void					add_token(t_token **tokens, t_token *token);
void					assert_is_builtin(t_token *token);
enum e_BuiltIn			get_builtin(t_token *token);
void					exec_builtin(t_token *token);
void					exec_echo(t_token *token);
void					exec_cd(t_token *token);
void					exec_pwd(t_token *token);
void					exec_exit(t_token *token);
void					exec_export(t_token *token);
void					exec_unset(t_token *token);
void					exec_env(t_token *token);

#endif

// Core