NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	srcs/ft_memset.c \
		srcs/ft_bzero.c \
		srcs/ft_calloc.c \
		srcs/ft_memcpy.c \
		srcs/ft_memmove.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_strdup.c \
		srcs/ft_strlcat.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strchr.c \
		srcs/ft_strrchr.c \
		srcs/ft_strnstr.c \
		srcs/ft_strncmp.c \
		srcs/ft_atoi.c \
		srcs/ft_isalpha.c \
		srcs/ft_isdigit.c \
		srcs/ft_isalnum.c \
		srcs/ft_isascii.c \
		srcs/ft_isprint.c \
		srcs/ft_toupper.c \
		srcs/ft_tolower.c \
		srcs/ft_substr.c \
		srcs/ft_strjoin.c \
		srcs/ft_strtrim.c \
		srcs/ft_split.c	\
		srcs/ft_itoa.c \
		srcs/ft_strmapi.c \
		srcs/ft_striteri.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putchar.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_putstr.c \
		srcs/ft_putstr.c

BSRCS = srcs/ft_lstnew_bonus.c \
		srcs/ft_lstadd_front_bonus.c \
		srcs/ft_lstsize_bonus.c \
		srcs/ft_lstlast_bonus.c \
		srcs/ft_lstadd_back_bonus.c \
		srcs/ft_lstdelone_bonus.c \
		srcs/ft_lstclear_bonus.c \
		srcs/ft_lstiter_bonus.c \
		srcs/ft_lstmap_bonus.c

PRINTF = srcs/printf/ft_printf.c \
		srcs/printf/hex_functions.c \
		srcs/printf/num_functions.c \
		srcs/printf/read_format.c

GNL = 	srcs/getnextline/get_next_line.c \
		srcs/getnextline/get_next_line_utils.c 

OBJS = ${SRCS:.c=.o} 

PRINTFOBJS = ${PRINTF:.c=.o}

GNLOBJS = ${GNL:.c=.o}

BOBJS = ${BSRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${PRINTFOBJS} ${GNLOBJS}
	ar -rc $@ $^

bonus: .bonus

.bonus: ${OBJS} ${BOBJS}
	ar -rc ${NAME} $^
	@touch .bonus

clean:
	@rm -f ${OBJS} ${BOBJS} ${PRINTFOBJS} ${GNLOBJS}

fclean: clean
	@rm -f ${NAME} .bonus

re: fclean all

rebonus: fclean bonus

.PHONY: clean bonus all