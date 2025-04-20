/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:11:27 by mgamraou          #+#    #+#             */
/*   Updated: 2025/04/19 14:27:15 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char *arg)
{
	int		i;
	char *builtins[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};

	while (builtins[i])
	{
		if (strcmp(arg, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	exec_builtin(char **arg, t_env *env_list)
{
	if (strncmp("echo ", arg[0], 4) == 0)
		ft_echo(arg);
	if (strncmp(arg[0], "cd", 2) == 0)
		ft_cd(arg);
	if (strncmp(arg[0], "pwd", 3) == 0)
		ft_pwd();
	if (strcmp("env", arg[0]) == 0)
		ft_env(env_list);

}

void	check_input(t_command *input, t_env *env_list, char **envp)
{
	t_command	*tmp;

	tmp = input;
	while (tmp)
	{
		if (is_builtin(tmp->args[0]) == 1)
			exec_builtin(tmp->args, env_list);
		else
			exec_cmd(tmp->args, envp);
		tmp = tmp->next;
	}
}
