/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:09:50 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/08 11:12:34 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_readline(char *input)
{
	while (1)
	{
		input = readline("minishell > ");
		add_history(input);
	}
	return (input);
}

void	check_syntax(char *input)
{
	t_token *token_list;
	int		i;

	token_list = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == '|')
			ft_add_token(&token_list, token_list->value, TOKEN_PIPE);
		i++;
	}
}

int main()
{
	t_token *tk = NULL;
	char *l = NULL;
	ft_readline(l);
	tokenize(l);
	printf("%s\n", tk->value);
}
