/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_exit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 15:54:06 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_exit(void)
{
	exit_msg(EXIT_SUCCESS, "exit\n");
	return (1);
}
