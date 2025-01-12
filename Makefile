SRCS = push_swap.c ft_atol.c libft.c libft2.c node_utils.c node_utils2.c operation_calls.c algorithm.c bitwise_utils.c operation_functions.c move_node.c
BONUS_FILES = checker_bonus.c ft_atol_bonus.c libft_bonus.c libft_bonus2.c node_utils_bonus.c operation_functions_bonus.c ft_split_bonus.c  node_utils2_bonus.c node_utils3_bonus.c  operation_calls_bonus.c
BONUS_SRCS = $(addprefix bonus/, $(BONUS_FILES))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
NAME = push_swap
BONUS = checker
FLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS)

%o: %c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all

.PHONY: all clean fclean re