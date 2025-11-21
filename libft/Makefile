NAME = libft.a
SRCS = ft_atoi.c \
	ft_itoa.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strncmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_lstnew.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	print_list_int.c

OBJS = ${SRCS:.c=.o}
INCLUDE = libft.h
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
