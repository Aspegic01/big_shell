/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:56:46 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/09 10:05:03 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_size(t_command *head)
{
	int count;

	while (head)
	{
		count = 0;
		while (head->args[count])
			count++;
		head->arg_size = count;
		head = head->next;
	}
}

void	set_type(t_command *head)
{
	while (head)
	{
		if (head->args != NULL)
		{
			if (ft_strncmp(head->args, "|", 2) == 0)
				head->type = TOKEN_PIPE;
			else if (ft_strncmp(head->args, ">>", 3) == 0)
				head->type = TOKEN_REDIR_APPEND;
			else if (ft_strncmp(head->args, ">", 2) == 0)
				head->type = TOKEN_REDIR_OUT;
			else if (ft_strncmp(head->args, "<", 2) == 0)
				head->type = TOKEN_REDIR_IN;
			else
				head->type = TOKEN_WORD;
		}
		head = head->next;
	}
}
