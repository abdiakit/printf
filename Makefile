SRCS = ft_strchr.c\
	   ft_putnbr_fd.c\
	   ft_putchar_fd.c\
	   ft_printf.c\
	   ft_print_unsig.c\
	   ft_print_string.c\
	   ft_print_p.c\
	   ft_print_hex_upp.c\
	   ft_print_hex.c\
	   ft_print_decimal.c\
	   ft_print_char.c\
	   ft_strlen.c\
	   ft_putstr_fd.c\

OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a

CC			= cc

RM			= rm -f
FLAGS		= -Wall -Werror -Wextra

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
