/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_pwd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 11:15:25 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_pwd(t_token *token)
{
	char	*cwd;

	(void)(token);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		printf("%s\n", cwd);
		free(cwd);
	}
}
