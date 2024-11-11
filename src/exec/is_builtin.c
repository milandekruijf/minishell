/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_builtin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 17:38:36 by daria         #+#    #+#                 */
/*   Updated: 2024/11/11 23:34:01 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(char *name)
{
	if (ft_strcmp(name, "exit") == 0)
		return (true);
	else if (ft_strcmp(name, "pwd") == 0)
		return (true);
	else if (ft_strcmp(name, "env") == 0)
		return (true);
	else if (ft_strcmp(name, "unset") == 0)
		return (true);
	else if (ft_strcmp(name, "export") == 0)
		return (true);
	else if (ft_strcmp(name, "cd") == 0)
		return (true);
	else if (ft_strcmp(name, "echo") == 0)
		return (true);
	return (false);
}
