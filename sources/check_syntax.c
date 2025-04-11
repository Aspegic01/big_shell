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

const char *token_to_string(token_type type)
{
    if (type == TOKEN_PIPE)
        return "|";
    if (type == TOKEN_REDIR_IN)
        return "<";
    if (type == TOKEN_REDIR_OUT)
        return ">";
    if (type == TOKEN_REDIR_APPEND)
        return ">>";
    if (type == TOKEN_HEREDOC)
        return "<<";
    return "unknown";
}

int check_syntax(t_token *tokens)
{
    t_token *prev = NULL;

    if (!tokens)
        return (1);
    while (tokens)
    {
        if (tokens->type == TOKEN_PIPE)
        {
            if (!prev || !tokens->next || tokens->next->type == TOKEN_PIPE)
            {
                fprintf(stderr, "minishell: syntax error near unexpected token `|'\n");
                return (0);
            }
        }
        else if (tokens->type == TOKEN_REDIR_IN || tokens->type == TOKEN_REDIR_OUT ||
                 tokens->type == TOKEN_REDIR_APPEND || tokens->type == TOKEN_HEREDOC)
        {
            if (!tokens->next || tokens->next->type == TOKEN_PIPE ||
                tokens->next->type == TOKEN_REDIR_IN || tokens->next->type == TOKEN_REDIR_OUT ||
                tokens->next->type == TOKEN_REDIR_APPEND || tokens->next->type == TOKEN_HEREDOC)
            {
                fprintf(stderr, "minishell: syntax error near unexpected token `%s'\n",
                        tokens->next ? token_to_string(tokens->next->type) : "newline");
                return (0);
            }
        }
        prev = tokens;
        tokens = tokens->next;
    }
    return 1;
}
