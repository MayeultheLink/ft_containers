NAME	=	ft_containers

SRCS	=	main.cpp

CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
OBJS	=	${SRCS:.cpp=.o}

all		:	${NAME}

$(NAME)	:	$(OBJS)
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean	:
		rm -f ${OBJS}

fclean	:
		rm -f ${OBJS}
		rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
