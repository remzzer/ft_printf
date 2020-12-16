# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrolland <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 15:14:50 by rrolland          #+#    #+#              #
#    Updated: 2020/07/29 16:46:15 by rrolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-c -Wall -Wextra -Werror
RM		=	rm -f

SRCS	=	ft_putnbr_fd.c ft_strlen.c ft_strjoin.c ft_putchar_fd.c \
	ft_toupper.c ft_putstr_fd ft_isdigit.c

OBJS	=	${SRCS:%.c=%.o}

%.o:		%.c
	${CC} ${CFLAGS} $< -o $@

$(NAME):	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib $(NAME)

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY : all clean fclean
