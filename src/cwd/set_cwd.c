/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_cwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:11:48 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 15:12:59 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_cwd(char *path, t_env_var_list *env_vars)
{
	set_env_var(env_vars, "PWD", path);
}
