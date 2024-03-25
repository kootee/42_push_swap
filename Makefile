NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #remove g after

SRCS = main.c \
		append_node.c \
		free_mem_functions.c \
		init_stack.c \
		is_sorted.c \
		push_swap_utils.c \
		push_swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		sort_ministack.c

LIBFT = libft/libft.a

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${OBJS} ${LIBFT} -o ${NAME}

libft/libft.a:
	${MAKE} -C libft

clean:
	rm -f ${OBJS}
	make clean -C libft

fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all