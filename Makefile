NAME = push_swap
CHECKER_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = execute_strategy.c \
	get_buddy.c \
	instruction_utils.c \
	instructions.c \
	find_cheapest_element.c \
	operations.c \
	parsing.c \
	push_swap.c \
	put_to_top.c \
	sort_helpers.c \
	sort_small.c \
	string_utils.c \
	utils_list.c

CHECKER_SRCS = checker_src/checker.c checker_src/checker_operations.c checker_src/operations_no_print.c parsing.c string_utils.c utils_list.c checker_src/get_next_line_checker.c

OBJS = ${SRCS:.c=.o}
CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C libftprintf
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a libftprintf/libftprintf.a -o $(NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	make -C libft
	make -C libftprintf
	$(CC) $(CFLAGS) $(CHECKER_OBJS) libft/libft.a libftprintf/libftprintf.a -o $(CHECKER_NAME)

checker: $(CHECKER_NAME)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	rm -f checker_src/*.o
	make clean -C libft
	make clean -C libftprintf

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	make fclean -C libft
	make fclean -C libftprintf

re: fclean all

re_checker: fclean checker

.PHONY: all clean fclean re checker re_checker
