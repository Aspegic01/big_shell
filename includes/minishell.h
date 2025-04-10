/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:49:55 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/04/10 10:14:38 by mlabrirh         ###   ########.fr       */
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
int	check_syntax(t_token *tokens);
t_token    *tokenize(const char *line);
t_command  *build_commands(t_token *tokens);
void        print_tokens(t_token *list);      // Optional for debug
void        print_commands(t_command *cmd);   // Optional for debug


#endif
