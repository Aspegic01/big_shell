/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:28:35 by mgamraou          #+#    #+#             */
/*   Updated: 2025/04/11 11:12:35 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;

	env_list = init_env(env);
	if (!env_list)
	{
		perror("Environment initialization failed");
		return (1);
	}
	while (1)
	{
		char	*rl = readline("minishell:");
		if (strcmp(rl, "exit") == 0)
			return (0);
		add_history(rl);
		if (strncmp("echo ", rl, 5) == 0)
			ft_echo(rl);
		if (strncmp(rl, "cd", 2) == 0)
			ft_cd(rl);
		if (strncmp(rl, "pwd", 3) == 0)
			ft_pwd();
		if (strcmp("env", rl) == 0)
			ft_env(env_list);
	}
}
