/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:09:00 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/07 19:17:01 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_add_token(t_token **token_list, char *value, token_type type)
{
	t_token	*new_token;
	t_token	*current;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = ft_strdup(value);
	new_token->type = type;
	new_token->next = NULL;

	if (*token_list == NULL)
	{
		*token_list = new_token;
		return (new_token);
	}
	current = *token_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_token;
	return (new_token);
}
