/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 14:37:13 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ----------------------------------------
// Includes
// ----------------------------------------

# include <stdbool.h>

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

struct s_global;
struct s_token;

typedef struct s_token
{
	int		type;
	char	*value;
}			t_token;

// ----------------------------------------
// Functions
// ----------------------------------------

// Utilities

int			ft_strcmp(const char *s1, const char *s2);

// Core

char		*get_builtins(void);
bool		is_builtin(t_token *token);

#endif