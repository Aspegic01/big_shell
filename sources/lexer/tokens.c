/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <mlabrirh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:53:24 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/21 10:53:46 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*tokenize(const char *input)
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
			char *quoted = read_quoted((char *)input, &i);
			if (!quoted)
				return 0;
			ft_add_token(&token_list, quoted, TOKEN_WORD);
			free(quoted);
		}
		else if (ft_is_operator(input[i]))
		{
			char *op = read_operator(input, &i);
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
