/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_env.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 15:54:11 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_env(t_env_var_list *env_vars)
{
	print_env_var_list(env_vars, false);
	return (1);
}
