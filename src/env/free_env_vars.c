/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env_vars.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 13:20:31 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_vars(t_env_var_list *env_vars)
{
	t_env_var	*curr;
	t_env_var	*prev;

	curr = env_vars->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free_env_var(prev);
	}
	env_vars->head = NULL;
	env_vars->tail = NULL;
}
