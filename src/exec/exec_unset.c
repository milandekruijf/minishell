/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_unset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 11:15:23 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_unset(t_token *token)
{
	(void)(token);
	printf("executing unset\n");
}
