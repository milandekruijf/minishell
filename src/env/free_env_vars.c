/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env_vars.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 15:13:32 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_vars(t_env_var_list **env_vars)
{
	t_env_var	*curr;
	t_env_var	*prev;

	if (env_vars == NULL || *env_vars == NULL)
		return ;
	curr = (*env_vars)->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free_env_var(&prev);
	}
	free(*env_vars);
	*env_vars = NULL;
}
