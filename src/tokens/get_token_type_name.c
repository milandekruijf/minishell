/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_token_type_name.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 13:57:02 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 13:29:04 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_token_type_name(enum e_TokenType type)
{
	if (type == TKN_UNKNOWN)
		return ("UNKNOWN");
	if (type == TKN_CMD)
		return ("CMD");
	if (type == TKN_ARG)
		return ("ARG");
	if (type == TKN_PIPE)
		return ("PIPE");
	if (type == TKN_REDIRECT_IN)
		return ("REDIRECT_IN");
	if (type == TKN_REDIRECT_IN_DELIM)
		return ("REDIRECT_IN_DELIM");
	if (type == TKN_REDIRECT_OUT)
		return ("REDIRECT_OUT");
	if (type == TKN_REDIRECT_OUT_APPEND)
		return ("REDIRECT_OUT_APPEND");
	return (NULL);
}
