/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:09:50 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/12 12:36:07 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

void print_commands(t_command *cmd)
{
	int i = 0;
	while (cmd)
	{
		printf("Command:\n");
		for (i = 0; i < cmd->arg_size; i++)
			printf("  Arg[%d]: %s\n", i, cmd->args[i]);
		printf("  Type: %d\n", cmd->type);
		cmd = cmd->next;
	}
}

void print_tokens(t_token *list)
{
	while (list)
	{
		printf("Token: %-10s | Type: %d\n", list->value, list->type);
		list = list->next;
	}
}

// int main(int ac, char **av, char **env)
// {
// 	(void)av;
// 	(void)ac;
// 	char *input;
// 	t_env	*env_list;
// 	env_list = init_env(env);
// 	while (1)
// 	{
// 		input = readline("minishell$ ");
// 		if (!input)
// 			break;
// 		if (*input)
// 			add_history(input);
// 		t_token *tokens = tokenize(input);
// 		expand_input(input, 0, env_list);
// 		if (!check_syntax(tokens))
// 			printf("syntax error\n");
// 		print_tokens(tokens);
//
// 		t_command *commands = build_commands(tokens);
// 		print_commands(commands);
// 		free(input);
// 	}
// 	return 0;
// }
int main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	char	*str;
	t_env	*list_env = NULL;
	char	*input;
	while(1)
	{
		init_env(env);
		str = readline("minishell: ");
		add_history(str);
		input = expand_input(str, 0, list_env);
		if (is_variable_assignment(str))
			handle_assignment(&list_env, input);
		else
			printf("%s\n", input);
	}
}
