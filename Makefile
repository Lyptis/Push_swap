SRCS	=	main.c	utils.c
HSRC	=	pushswap.h
OBJS	=	${SRCS:.c=.o}

NAME	= pushswap

GCC		= gcc
RM		= rm -f
FLAGS	= #-Wall -Wextra -Werror

.c.o:		${HSRC}
			${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${OBJS} -L libft -lft

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${HSRC}.gch

fclean:		clean
			${RM} ${NAME}

re:			fclean all
