/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_env.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/31 14:28:51 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_env(t_env_var_list *env_vars)
{
	print_env_var_list(env_vars, false);
}
