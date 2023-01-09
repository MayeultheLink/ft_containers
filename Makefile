NAME	=	ft_containers

SRCS	=	main.cpp

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	${SRCS:.c=.o}
		
all		:	${NAME}

$(NAME)	:	 $(OBJS)
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean	:
		rm -f ${OBJS}

fclean	:
		rm -f ${OBJS}
		rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
