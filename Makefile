NAME	=	libftprintf.a
SRC		=	ft_printf.c \
			utils/ft_atoi.c utils/ft_isdigit.c utils/ft_strlen.c \
			print_utils/print_sn.c print_utils/print_un.c print_utils/print_c.c \
			parsing/get_format.c parsing/parser.c parsing/validation.c \
			processing/processor.c processing/process_char.c processing/process_str.c processing/process_signed.c processing/process_usigned.c
HEAD	=	ft_printf.h utils/utils.h
OBJ		=	${SRC:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
.PHONY	:	all clean fclean re run bonus

all		:	${NAME}

${NAME}	:	${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

${OBJ}	:	${HEAD}


clean	:	
			rm -f ${OBJ} ${OBJ_B}

fclean	:	clean
			rm -f ${NAME}

re		:	fclean all

bonus	:	${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

run		:
			${CC} main.c -L . -lftprintf -g -fsanitize=address


