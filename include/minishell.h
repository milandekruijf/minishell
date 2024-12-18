/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 16:03:03 by mde-krui      ########   odam.nl         */
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
# include <stdarg.h>
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

# define MS_WHITESPACE_CHARS " \t\n\v\f\r"

# ifndef MS_BUFFER_SIZE
#  define MS_BUFFER_SIZE 1024
# endif

// ----------------------------------------
// Enums
// ----------------------------------------

enum					e_ExitCode
{
	MS_EXIT_SUCCESS = 0,
	MS_EXIT_ASSERT_FAILED,
	MS_EXIT_CMD_NOT_FOUND,
};

typedef enum e_TokenType
{
	TKN_UNKNOWN,
	TKN_WORD,
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

typedef struct s_tkn
{
	enum e_TokenType	type;
	char				*value;
	struct s_tkn		*next;
}						t_tkn;

typedef struct s_tkn_list
{
	struct s_tkn		*head;
	struct s_tkn		*tail;
}						t_tkn_list;

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

typedef struct s_cmd
{
	char				**argv;
	struct s_cmd		*next;
	pid_t				pid;
}						t_cmd;

typedef struct s_cmd_list
{
	struct s_cmd		*head;
	struct s_cmd		*tail;
}						t_cmd_list;

typedef struct s_piping
{
	int					in;
	int					out;
	int					**pipes;
	int					count;
}						t_piping;

typedef struct s_sig
{
	bool				sigint;
	int					status;
	pid_t				pid;
}						t_sig;

// ----------------------------------------
// Globals
// ----------------------------------------

extern t_sig			g_sig;

// ----------------------------------------
// Functions
// ----------------------------------------

// Cmds

void					add_cmd(t_cmd_list *list, t_cmd *cmd);
t_cmd					*create_empty_cmd(void);
t_cmd_list				*create_cmd_list(void);
void					init_cmd_list(t_cmd_list *list);
t_cmd_list				*parse_cmds(t_tkn_list *tokens);
void					free_cmd_list(t_cmd_list **list);
void					free_cmd(t_cmd **cmd);

// Exit

void					exit_msg(int status, const char *format, ...);

// Utils

char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
size_t					ft_strlen(const char *s);
char					*ft_strndup(const char *s, ssize_t n);
void					*ms_malloc(size_t size);
void					ms_assert(bool predicate, const char *format, ...);
char					*ft_strdup(const char *s);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strtok(char *str, const char *delim);
char					*join_argv(const char **argv);
int						ft_sprintf(char *str, const char *format, ...);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_realloc(void *ptr, size_t size);
void					ft_fputs(const char *s, int fd);
char					*ft_strncpy(char *dest, const char *src, size_t n);
bool					ft_isspace(int c);
char					*ft_itoa(int n);
int						ft_abs(int n);
int						ndigits(int n, int base);
size_t					ft_strcspn(const char *s, const char *reject);
int						ft_dprintf(int fd, const char *format, ...);
int						ft_vsprintf(char *str, const char *format, va_list ap);
int						ft_vsnprintf(char *str, size_t size, const char *format,
							va_list ap);
int						ft_snprintf(char *str, size_t size, const char *format,
							...);
int						ft_vdprintf(int fd, const char *format, va_list ap);
char					*strfmt(const char *format, ...);
int						ft_vprintf(const char *format, va_list ap);
int						ft_printf(const char *format, ...);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
char					*ft_strstr(const char *big, const char *little);

// Cwd

char					*get_cwd(void);
void					set_cwd(char *cwd, t_env_var_list *env_vars);

// Err

void					vexit_err(int status, const char *format, va_list ap);
void					vprint_err(const char *format, va_list ap);
void					exit_err(int status, const char *format, ...);
void					print_err(const char *format, ...);

// Signals

void					init_sig(void);
void					handle_sigint(int sig);
void					listen_sigint(void);

// Env

void					print_envp(const char **envp);
t_env_var_list			*parse_envp(const char **envp);
void					print_env_var(t_env_var *var, bool pretty);
void					add_env_var(t_env_var_list *list, t_env_var *var);
void					init_env_var_list(t_env_var_list *list);
void					print_env_var_list(const t_env_var_list *list,
							bool pretty);
t_env_var				*create_env_var(const char *key, const char *value);
t_env_var				*get_env_var(t_env_var_list *list, const char *key);
void					free_env_var(t_env_var **var);
void					free_env_var_list(t_env_var_list **list);
t_env_var_list			*create_env_var_list(void);
char					**env_var_list_to_envp(t_env_var_list *list);
size_t					get_env_var_list_size(t_env_var_list *list);
void					unset_env_var(t_env_var_list *list, const char *key);
void					set_env_var(t_env_var_list *list, const char *key,
							const char *value);
t_env_var				*ensure_env_var(t_env_var_list *env_vars,
							const char *key, const char *message);

// Tkns

void					add_tkn(t_tkn_list *tokens, t_tkn *tkn);
void					init_tkn_list(t_tkn_list *list);
t_tkn					*create_tkn(t_token_type type, const char *value);
t_tkn_list				*parse_tkns(char *line);
void					print_tkn(t_tkn *tkn);
void					print_tkn_list(t_tkn_list *list);
char					*get_tkn_type_name(enum e_TokenType type);
void					free_tkn(t_tkn **tkn);
t_tkn_list				*create_tkn_list(void);
void					free_tkn_list(t_tkn_list **list);

// Exec

void					exec(t_cmd_list *cmds, t_env_var_list *env_vars);
int						exec_exit(void);
int						exec_pwd(void);
void					exec_bin(t_cmd *cmd, t_env_var_list *env_vars);
int						exec_path(t_cmd *cmd, t_env_var_list *env_vars);
int						exec_abs(t_cmd *cmd, t_env_var_list *env_vars);
int						exec_env(t_env_var_list *env_vars);
int						exec_unset(const char **argv, t_env_var_list *env_vars);
int						exec_export(const char **argv,
							t_env_var_list *env_vars);
int						exec_echo(const char **argv, t_env_var_list *env_vars);
int						exec_cd(const char **argv, t_env_var_list *env_vars);
int						exec_builtin(t_cmd *cmd, t_env_var_list *env_vars);
void					exec_in_fork(t_cmd *cmd, t_env_var_list *env_vars,
							t_piping piping);
bool					is_builtin(char *name);
void					close_pipes(int **pipes, int count, int in_to_keep,
							int out_to_keep);
void					free_pipes(int ***pipes, int count);
int						**allocate_pipes(int count);

// Run

void					run_it(t_env_var_list *env_vars);
void					run_c(char *c, t_env_var_list *env_vars);

// Vars

char					*expand_vars(const char *str, t_env_var_list *env_vars);

#endif
