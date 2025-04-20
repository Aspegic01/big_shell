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
	t_command	*input;

	env_list = init_env(env);
	if (!env_list)
	{
		perror("Environment initialization failed");
		return (1);
	}
	// input from moad
	check_input(input, env_list, env);
}
