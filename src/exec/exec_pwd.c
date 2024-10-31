/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_pwd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/31 15:10:53 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_pwd(t_env_var_list *env_vars)
{
	printf("%s\n", get_cwd(env_vars));
}
