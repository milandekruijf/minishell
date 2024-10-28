/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_tests.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 12:28:57 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TESTS_H
# define MINISHELL_TESTS_H

# include "acutest.h"
# include "minishell.h"

void	test_parse_tokens(void);
void	test_parse_envp(void);
void	test_get_env_var(void);

#endif
