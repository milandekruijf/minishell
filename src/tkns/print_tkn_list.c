/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tkn_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 13:32:54 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:33:03 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tkn_list(t_tkn_list *list)
{
	t_tkn	*tkn;

	tkn = list->head;
	while (tkn)
	{
		print_tkn(tkn);
		tkn = tkn->next;
	}
}
