# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 11:31:47 by mlabrirh          #+#    #+#              #
#    Updated: 2025/04/08 11:33:34 by mlabrirh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	cc
FLAGS =	-Wall -Wextra -Werror -lreadline
NAME = minishell

SRCS =	$(shell ls ./libft/*.c) \
		$(shell ls ./sources/*.c)
OFILES = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean
