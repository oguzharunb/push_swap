SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%o: %c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re