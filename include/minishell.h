/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 13:16:48 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

struct s_cmd;
struct s_global;
struct s_file;

typedef struct s_global
{
	int argc;
	char *argv;
	struct s_cmd *cmds;
} t_global;

typedef struct s_cmd
{
	struct s_global *global;
	char *name;
	char *args;
} t_cmd;

typedef struct s_file
{
	struct s_global *global;
	int fd;
} t_file;

#endif