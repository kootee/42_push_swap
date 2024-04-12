NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c \
		push_swap_utilities/stack_utils.c \
		push_swap_utilities/free_mem_functions.c \
		push_swap_utilities/push_swap_utils.c \
		sort_algorithms/check_dbl_rotation.c \
		sort_algorithms/sort_ministack.c \
		sort_algorithms/push_swap.c \
		sort_algorithms/sort_b_stack.c \
		stack_commands/reverse_rotate.c \
		stack_commands/rotate.c \
		stack_commands/push.c \
		stack_commands/swap.c \
		stack_init/append_node.c \
		stack_init/init_stack.c \
		stack_init/calculate_stack_position.c

LIBFT = libft/libft.a

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${OBJS} ${LIBFT} -o ${NAME}

libft/libft.a:
	${MAKE} -C libft

clean:
	@echo "cleaning push_swap..."
	@rm -f ${OBJS}
	@make clean -C libft

fclean: clean
	@echo "fcleaning push_swap..."
	@rm -f ${NAME}
	@make fclean -C libft

re: fclean all