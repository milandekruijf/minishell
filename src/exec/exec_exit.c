/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_exit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 11:12:07 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_exit(t_token *token)
{
	(void)(token);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
