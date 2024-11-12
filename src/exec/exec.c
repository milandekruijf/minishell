/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:03:45 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 01:48:47 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_list_len(t_cmd_list *cmds)
{
	int		count;
	t_cmd	*cmd;

	count = 0;
	cmd = cmds->head;
	while (cmd)
	{
		count += 1;
		cmd = cmd->next;
	}
	return (count);
}

void	exec_multiple(t_cmd_list *cmds, t_env_var_list *env_vars)
{
	int			i;
	t_cmd		*cmd;
	t_piping	piping;

	piping.count = cmd_list_len(cmds);
	piping.pipes = allocate_pipes(piping.count);
	i = 1;
	while (i <= piping.count)
		pipe(piping.pipes[i++]);
	piping.pipes[0][0] = STDIN_FILENO;
	piping.pipes[0][1] = -1;
	piping.pipes[piping.count][1] = STDOUT_FILENO;
	piping.pipes[piping.count][0] = -1;
	cmd = cmds->head;
	i = 1;
	while (cmd)
	{
		piping.in = piping.pipes[i - 1][0];
		piping.out = piping.pipes[i][1];
		exec_in_fork(cmd, env_vars, piping);
		cmd = cmd->next;
		++i;
	}
	cmd = cmds->head;
	close_pipes(piping.pipes, piping.count, STDIN_FILENO, STDOUT_FILENO);
	while (cmd)
	{
		fprintf(stderr, "waiting for child %d\n", cmd->pid);
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	free_pipes(&piping.pipes, piping.count);
}

void	exec_one(t_cmd *cmd, t_env_var_list *env_vars)
{
	pid_t	pid;

	if (is_builtin(cmd->argv[0]))
		exec_builtin(cmd, env_vars);
	else
	{
		pid = fork();
		if (pid == 0)
			exec_bin(cmd, env_vars);
		else
			waitpid(pid, NULL, 0);
	}
}

void	exec(t_cmd_list *cmds, t_env_var_list *env_vars)
{
	if (cmds->head->next == NULL)
		exec_one(cmds->head, env_vars);
	else
		exec_multiple(cmds, env_vars);
}
