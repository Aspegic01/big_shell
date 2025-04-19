/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:17:15 by mgamraou          #+#    #+#             */
/*   Updated: 2025/04/18 10:25:29 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_exec(char *path, char **args, char **envp)
{
	if (!path)
	{
		ft_putstr_fd("command not found\n", 2);
		clean_up(path, args);
		exit(127);
	}
	if (execve(path, args, envp) == -1)
	{
		perror("failes to execute command");
		clean_up(path, args);
		exit(126);
	}
}

void	exec_cmd(char **args, char **envp)
{
	pid_t	pid;
	char	*cmd_path;

	pid = fork();
	if (pid == 0)
	{
		cmd_path = find_cmd_path(args[0], envp);
		handle_exec(cmd_path, args, envp);
	}
	else
		wait(NULL);
}
