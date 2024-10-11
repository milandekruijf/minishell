/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 15:08:11 by mde-krui      ########   odam.nl         */
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

// Tokens

# define TKN_CMD 0
# define TKN_ARG 1
# define TKN_FILE 2
# define TKN_PIPE 3

# define TKN_REDIRECT_IN_DELIM 4
# define TKN_REDIRECT_IN 5

# define TKN_REDIRECT_OUT 6
# define TKN_REDIRECT_OUT_APPEND 7

// ----------------------------------------
// Structures
// ----------------------------------------

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
}					t_token;

// ----------------------------------------
// Functions
// ----------------------------------------

// Utilities

int					ft_strcmp(const char *s1, const char *s2);

// Core

bool				is_builtin(t_token *token);
t_token				*get_last_token(t_token *tokens);
t_token				*create_token(char *value);
void				add_token(t_token **tokens, t_token *token);

#endif