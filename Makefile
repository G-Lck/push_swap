NAME = push_swap.out
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
	utils_list.c \
	libft/libft.a \
	libftprintf/libftprintf.a

OBJS = ${SRCS:.c=.o}
INCLUDE = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

$(NAME) :
	make -C libft
	make -C libftprintf
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C libftprintf

clean :
	$(RM) $(NAME)
	make clean -C libft
	make clean -C libftprintf

re : fclean all
