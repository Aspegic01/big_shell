/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:13:03 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/10 10:14:23 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax(t_token *tokens)
{
	t_token *prev = NULL;

	while (tokens)
	{
		if (tokens->type == TOKEN_PIPE)
		{
			if (!prev)
			{
				fprintf(stderr, "minishell: syntax error near unexpected token `|'\n");
				return (0);
			}
			if (!tokens->next || tokens->next->type == TOKEN_PIPE)
			{
				fprintf(stderr, "minishell: syntax error near unexpected token `|'\n");
				return (0);
			}
		}
		else if (tokens->type == TOKEN_REDIR_IN || tokens->type == TOKEN_REDIR_OUT
			|| tokens->type == TOKEN_REDIR_APPEND || tokens->type == TOKEN_HEREDOC)
		{
			if (!tokens->next || tokens->next->type != TOKEN_WORD)
			{
				fprintf(stderr, "minishell: syntax error near unexpected token `newline'\n");
				return (0);
			}
		}
		prev = tokens;
		tokens = tokens->next;
	}
	return (1);
}
