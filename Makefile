SRCS	=	main.c	set_indexs.c get_input.c rules.c	rules2.c sort.c
HSRC	=	pushswap.h
OBJS	=	${SRCS:.c=.o}

NAME	= push_swap

GCC		= gcc
RM		= rm -f
FLAGS	= #-Wall -Wextra -Werror

.c.o:		${HSRC}
			${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ./libft
			${GCC} -o ${NAME} ${OBJS} -L libft -lft

all:		${NAME}

clean:
			make clean -C ./libft
			${RM} ${OBJS}
			${RM} ${HSRC}.gch

fclean:		clean
			make fclean -C ./libft
			${RM} ${NAME}

re:			fclean all
