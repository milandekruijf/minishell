/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_env_var.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:21:22 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/18 15:24:59 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_var(t_env_var *var)
{
	printf("EnvVar { Key: %s, Value: %s }\n", var->key, var->value);
}
