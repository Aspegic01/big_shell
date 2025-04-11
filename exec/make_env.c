/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:12:18 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/11 13:13:23 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*new_node(char **variable)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->var_name = ft_strdup(variable[0]);
	if (!node->var_name)
		return (free(node), NULL);
	if (variable[1])
	{
		node->var_value = ft_strdup(variable[1]);
		if (!node->var_value)
		{
			free(node->var_name);
			return (free(node), NULL);
		}
	}
	else
		node->var_value = NULL;
	node->exported = 1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_env **env_list, t_env *new_n)
{
	t_env	*current;

	if (!*env_list)
	{
		*env_list = new_n;
		return ;
	}
	current = *env_list;
	while (current->next)
		current = current->next;
	current->next = new_n;
	new_n->prev = current;
}

void free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

t_env	*init_env(char	**env)
{
	t_env	*env_list;
	t_env	*new;
	char	**variable;
	int		i;

	env_list = NULL;
	i = 0;
	while (env[i])
	{
		variable = ft_split(env[i], '=');
		new = new_node(variable);
		add_node(&env_list, new);
		free_split(variable);
		i++;
	}
	return (env_list);
}
