/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:12:08 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/19 16:02:36 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_value(t_env *env_list, const char *var_name)
{
	while (env_list)
	{
		if (ft_strcmp(env_list->var_name, var_name) == 0)
			return (env_list->var_value);
		env_list = env_list->next;
	}
	return (NULL);
}

static bool is_valid_var_char(char c, bool first_char)
{
	if (first_char)
		return (ft_isalpha(c) || c == '_');
	return (ft_isalnum(c) || c == '_');
}

static void	ft_exit_status(int exit_status, char **result, char **start)
{
	char	*exit_code;

	exit_code = ft_itoa(exit_status);
	*result = strjoin_and_free(*result, exit_code);
	free(exit_code);
	*start += 2;
}

static void	ft_env_vars(t_env *env_list, char **result, char **start)
{
	char	*var_name;
	char	*var_value;
	char	*var_start;

	var_start = ++(*start);
	while (is_valid_var_char(**start, *start == var_start))
		(*start)++;
	var_name = ft_strndup(var_start, *start - var_start);
	var_value = get_env_value(env_list, var_name);
	if (var_value)
		*result = strjoin_and_free(*result, var_value);
	free(var_name);
}

char *expand_env_vars(char *input, int exit_status, t_env *env_list)
{
	char	*result;
	char	*start;
	char	temp[2];

	if (handle_assignment(&env_list, input))
		return ft_strdup(input);
	start  = input;
	result = ft_strdup("");
	while (*start)
	{
		if (*start == '$' && (is_valid_var_char(*(start + 1), true) || *(start + 1) == '?'))
			if (*(start + 1) == '?')
				ft_exit_status(exit_status, &result, &start);
			else
				ft_env_vars(env_list, &result, &start);
		else
		{
			temp[0] = *start;
			temp[1] = '\0';
			result = strjoin_and_free(result, temp);
			start++;
		}
	}
	return (result);
}
