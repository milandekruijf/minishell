/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env_var.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 15:10:30 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_var(t_env_var **var)
{
	free((*var)->key);
	free((*var)->value);
	free(*var);
	*var = NULL;
}
