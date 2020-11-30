SRC =  ./src/conv_hex.c
SRC += ./src/function_help.c
SRC += ./src/function_help_02.c
#SRC += ./src/function_help_03.c
SRC += ./src/ft_printf.c
SRC += ./src/initialize.c
SRC += ./src/printf_flags.c

INCLUDES = ./includes/ft_printf.h

OBJS = ${SRC:.c=.o}

NAME = libftprintf.a

LIBFT = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

${NAME}: ${OBJS}
		make -C ./libft #-C change directory
		cp libft/libft.a ./${NAME}
		ar -rcs ${NAME} ${OBJS}

all : ${NAME}

.c.o:
		${CC} ${FLAGS} -o $@ -c $< -I${INCLUDES}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY: clean all fclean re

