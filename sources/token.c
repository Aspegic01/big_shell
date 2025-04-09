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
		if (input[i] == '|')
		{
			ft_add_token(&token_list, "|", TOKEN_PIPE);
			i++;
		}
		else if (input[i] == '>')
		{
			if (input[i + 1] == '>')
			{
				ft_add_token(&token_list, ">>", TOKEN_REDIR_APPEND);
				i += 2;
			}
			else
			{
				ft_add_token(&token_list, ">", TOKEN_REDIR_OUT);
				i++;
			}
		}
		else
		{
			int start = i;
			while (input[i] && input[i] != ' ' && input[i] != '\t' && 
				input[i] != '|' && input[i] != '<' && input[i] != '>')
				i++;
			char *word = ft_substr(input, start, i - start);
			ft_add_token(&token_list, word, TOKEN_WORD);
			free(word);
		}
	}
	return token_list;
}

