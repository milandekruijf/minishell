/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_env_var.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:21:22 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/31 14:28:14 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_var(t_env_var *var, bool pretty)
{
	if (pretty)
		printf("EnvVar { Key: %s, Value: %s }\n", var->key, var->value);
	else
		printf("%s=%s\n", var->key, var->value);
}
