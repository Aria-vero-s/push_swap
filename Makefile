NAME = push_swap

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -ggdb3

# INCLUDES = 

# LIBS = 

SRCS = sources/push_swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all