/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_exit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/18 14:07:15 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_exit(t_token *token)
{
	exit(EXIT_FAILURE);
}
