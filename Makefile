SRC = mandatory/push_swap.c \
	functions/ft_strlen.c \
	functions/ft_isalpha.c \
	functions/ft_atoi.c \
	functions/ft_split.c \
	functions/ft_isdigit.c \
	functions/ft_putstr_fd.c \
	mandatory/to_stack.c \
	mandatory/sort_stack.c \
	mandatory/sort_array.c \
	mandatory/LongestincreasingSub.c \
	mandatory/ft_push_to_b.c \
	mandatory/ft_utils.c \
	mandatory/cost.c \
	mandatory/cas_1.c \
	mandatory/ft_free.c \
	mandatory/best_element.c \
	mandatory/fun_checking.c \
	mandatory/initial_fun.c \
	mandatory/move_fun.c \
	mandatory/stack_op.c \
	mandatory/aide_norm.c

BNS = bonus/push_swap_bonus.c \
	bonus/utils_bonus.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	bonus/to_stack_bonus.c \
	functions/ft_strlen.c \
	functions/ft_isalpha.c \
	functions/ft_atoi.c \
	functions/ft_split.c \
	functions/ft_isdigit.c \
	functions/ft_putstr_fd.c \
	bonus/ft_free_bonus.c \
	bonus/checking_bonus.c \
	bonus/utils_2_bonus.c

OBJF = $(SRC:.c=.o)

OBNS = $(BNS:.c=.o)

NAME = push_swap

BONUS = checker

C = cc

CFLAGS = -Wall -Werror -Wextra  #-fsanitize=address -g

all: $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJF)
		$(C) $(CFLAGS) $(OBJF) -o $(NAME)

$(BONUS): $(OBNS)
		$C $(OBNS) -o $(BONUS) 


clean:
	rm -rf $(OBJF) $(OBNS)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus