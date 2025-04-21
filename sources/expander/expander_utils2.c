/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:14:16 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/19 15:17:53 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *strjoin_and_free(char *s1, char *s2)
{
	char *result;

	if (!s1 && !s2)
		return NULL;
	if (!s1)
		return ft_strdup(s2);
	if (!s2)
		return s1;    
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char *remove_quotes(char *input)
{
	char	*result;
	char	*start;
	char	quote;
	char	temp[2];

	result = ft_strdup("");
	start = input;
	quote = '\0';
	while (*start)
	{
		if ((*start == '\'' || *start == '"') && !quote)
		{
			quote = *start;
			start++;
		}
		else if (*start == quote)
		{
			quote = '\0';
			start++;
		}
		else
		{
			temp[0] = *start;
			temp[1] = '\0';
			result = strjoin_and_free(result, temp);
			start++;
		}
	}
	free(input);
	return (result);
}

char *expand_tilde(char *input)
{
	char	*home;
	char	*expanded;

	if (input[0] == '~' && (input[1] == '/' || input[1] == '\0'))
	{
		home = getenv("HOME");
		if (home)
		{
			expanded = malloc(ft_strlen(home) + ft_strlen(input) + 1);
			if (!expanded)
				return (ft_strdup(input));
			strcpy(expanded, home);
			strcat(expanded, input + 1);
			return expanded;
		}
	}
	return (ft_strdup(input));
}
