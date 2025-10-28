NAME = push_swap.out
SRCS = check_unicity.c \
	convert_numbers_to_position.c \
	ft_atoi.c \
	ft_itoa.c \
	lst_is_sorted.c \
	instructions.c \
	parsing.c \
	push_swap.c \
	push.c \
	swap.c \
	rotate.c \
	try_to_swap.c \
	sort.c \
	convert_arr_to_list.c \
	utils_libft.c \
	utils_list.c \
	libftprintf/libftprintf.a

OBJS = ${SRCS:.c=.o}
INCLUDE = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

$(NAME) :
	make -C libftprintf
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libftprintf

clean :
	$(RM) $(NAME)
	make clean -C libftprintf

re : fclean all
