NAME = push_swap.out
SRCS = check_unicity.c \
	lst_is_sorted.c \
	instructions.c \
	parsing.c \
	push_swap.c \
	push.c \
	swap.c \
	rotate.c \
	sort_small.c \
	sort_helpers.c \
	instruction_utils.c \
	convert_arr_to_list.c \
	get_buddy.c \
	get_position.c \
	min_moves.c \
	put_to_top.c \
	reverse_rotate.c \
	less_cost_in_stack_a.c \
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
