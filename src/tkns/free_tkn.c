/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tkn.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:42:27 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tkn(t_tkn **tkn)
{
	free((*tkn)->value);
	free(*tkn);
	*tkn = NULL;
}
