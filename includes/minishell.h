/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:49:55 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/06 13:51:08 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
#define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef enum
{
	TOKEN_WORD,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_IN,
	TOKEN_PIPE,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC
} token_type;

typedef struct s_token
{
	char			*value;
	token_type		type;
	struct s_token	*next;
} t_token;

typedef struct s_command
{
	char				**args;
	token_type			type;
	int					arg_size;
	int					heredoc;
	struct	s_command	*next;
} t_command;

t_token	*ft_add_token(t_token **token_list, char *value, token_type type);
void	check_syntax(char *input);
t_token	*tokenize(char *input);

#endif
