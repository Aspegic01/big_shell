/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:57:27 by mgamraou          #+#    #+#             */
/*   Updated: 2025/04/07 11:00:22 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



int	ft_cd(char *arg)
{
	char	current_dir[1024];
	char	*path;
	char	**args = ft_split(arg, ' ');
	int	ret;

	if (args[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			fprintf(stderr, "minishell: cd: HOME not set\n");
			return 1;
		}
	}
	else
		path = args[1];
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("minishell: cd: getcwd error");
		return 1;
	}
	ret = chdir(path);
	if (ret != 0)
	{
		fprintf(stderr, "minishell: cd: %s: %s\n", path, strerror(errno));
		return 1;
	}
	return 0;
}

void	ft_echo(char *arg)
{
	char	**args = ft_split(arg, ' ');
	int	i = 1;
	int	print_newline = 1;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		int	j = 2;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break;
		print_newline = 0;
		i++;
	}
	int	first = 1;
	while (args[i])
	{
		if (!first)
			printf(" ");
		printf("%s", args[i]);
		first = 0;
		i++;
	}
	if (print_newline)
		printf("\n");
}

int	main(int ac, char **av, char **env)
{
	char	current_dir[1024];
	while (1)
	{
		char	*rl = readline(">");
		if (strcmp(rl, "exit") == 0)
			return (0);
		add_history(rl);
		if (strncmp("echo ", rl, 5) == 0)
			ft_echo(rl);
		if (strncmp(rl, "cd", 2) == 0)
			ft_cd(rl);
		if (strncmp(rl, "pwd", 3) == 0)
		{
			getcwd(current_dir, sizeof(current_dir));
			printf("%s\n", current_dir);
		}
	}
}
