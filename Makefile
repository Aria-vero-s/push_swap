# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 22:28:15 by ariane            #+#    #+#              #
#    Updated: 2025/02/18 21:03:22 by asaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

SRCS = sources/checks.c \
		sources/input.c \
		sources/input2.c \
		sources/main.c \
		sources/ops_base.c \
		sources/ops_push.c \
		sources/ops_rotate.c \
		sources/ops_swap.c \
		sources/sort_big.c \
		sources/sort_mini.c \
		sources/sort_mini2.c \
		sources/utils.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all