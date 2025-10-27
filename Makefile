NAME = push_swap.out
SRCS = ft_atoi.c \
	ft_itoa.c \
	parsing.c \
	push_swap.c \
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
