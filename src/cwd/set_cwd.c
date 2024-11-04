/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_cwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:11:48 by anonymous     #+#    #+#                 */
/*   Updated: 2024/11/04 11:55:12 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_cwd(char *cwd, t_env_var_list *env_vars)
{
	chdir(cwd);
	set_env_var(env_vars, "PWD", get_cwd());
}
