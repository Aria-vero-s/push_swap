# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariane <ariane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 22:28:15 by ariane            #+#    #+#              #
#    Updated: 2025/01/19 14:48:46 by ariane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -ggdb3

INCLUDES = -Iincludes

# LIBS = 

SRCS = sources/main.c sources/radix.c sources/push_swap1.c sources/push_swap2.c sources/operations.c sources/input.c sources/stack.c sources/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all