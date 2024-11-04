/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_vars.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 13:11:18 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 13:48:01 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_vars(const char *str, t_env_var_list *env_vars)
{
	char		*res;
	const char	*curr;
	const char	*prefix;
	t_env_var	*env_var;

	res = ft_strdup("");
	curr = str;
	while (*curr)
	{
		prefix = ft_strchr(curr, '$');
		if (!prefix)
		{
			res = ft_strcat(res, curr);
			break ;
		}
		res = ft_strncat(res, curr, prefix - curr);
		curr = prefix + 1;
		if (ft_isspace(*curr) || *curr == '\0')
		{
			res = ft_strcat(res, "$");
			continue ;
		}
		env_var = get_env_var(env_vars, ft_strtok((char *)curr, ' '));
		if (!env_var)
			break ;
		res = ft_strcat(res, env_var->value);
		curr += ft_strlen(env_var->key);
	}
	return (res);
}