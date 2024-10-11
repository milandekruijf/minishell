/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_builtins.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:55:00 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 13:55:27 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_builtins(void)
{
	char builtins[7];

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";

	return (builtins);
}