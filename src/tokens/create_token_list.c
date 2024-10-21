/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_token_list.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 15:05:19 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 15:05:46 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_list	*create_token_list(void)
{
	t_token_list	*list;

	list = ms_malloc(sizeof(t_token_list));
	init_token_list(list);
	return (list);
}
