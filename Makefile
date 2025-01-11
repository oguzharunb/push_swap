SRCS = push_swap.c ft_atol.c ft_split.c libft.c libft2.c node_utils.c node_utils2.c operation_calls.c algorithm.c bitwise_utils.c operation_functions.c move_node.c
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