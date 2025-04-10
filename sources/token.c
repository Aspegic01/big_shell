/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:39:54 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/08 16:49:32 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*read_quoted(char *input, int *i)
{
	(void)i;
	return input;
}

char	*read_operation(char *input, int *i)
{
	(void)i;
	return input;
}

char *read_word(const char *str, int *i)
{
    int start = *i;
    while (str[*i] && !ft_whitespace(str[*i]) && !ft_is_operator(str[*i]) && str[*i] != '\'' && str[*i] != '"')
        (*i)++;
    return strndup(&str[start], *i - start);
}


token_type	get_operation_type(const char *op)
{
	if (ft_strcmp(op, ">") == 0)
		return (TOKEN_REDIR_OUT);
	if (ft_strcmp(op , ">>") == 0)
		return (TOKEN_REDIR_APPEND);
	if (ft_strcmp(op, "<") == 0)
		return (TOKEN_REDIR_IN);
	if (ft_strcmp(op, "<<") == 0)
		return (TOKEN_HEREDOC);
	if (ft_strcmp(op, "|") == 0)
		return (TOKEN_PIPE);
	return (TOKEN_WORD);
}

t_token	*tokenize(char *input)
{
	t_token	*token_list = NULL;
	int	i = 0;

	while(input[i])
	{
		while(input[i] && ft_whitespace(input[i]))
			i++;
		if (!input[i])
			break ;
		if (input[i] == '\'' || input[i] == '"')
		{
			char *quoted = read_quoted(input, &i);
			ft_add_token(&token_list, quoted, TOKEN_WORD);
			free(quoted);
		}
		else if (ft_is_operator(input[i]))
		{
			char *op = read_operation(input, &i);
			token_type type = get_operation_type(op);
			ft_add_token(&token_list, op, type);
		}
		else if (input[i] != '\0')
		{
			char *word = read_word(input, &i);
			ft_add_token(&token_list, word, TOKEN_WORD);
			free(word);
		}
	}
	return token_list;
}
