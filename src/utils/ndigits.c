/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ndigits.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: muijf <muijf@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 17:13:17 by muijf         #+#    #+#                 */
/*   Updated: 2024/11/04 14:02:19 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ndigits(int n, int base)
{
	int	res;

	res = 1;
	while (n / base)
	{
		res++;
		n /= base;
	}
	return (res);
}
