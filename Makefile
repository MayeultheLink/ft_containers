NAME		=	ft_containers

SRCS		=	main.cpp

CC		=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
OBJS		=	${SRCS:.cpp=.o}

all		:	${NAME}

$(NAME)	:	$(OBJS)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

vector		:
			@bash ./tester/vector.sh
map		:
			@bash ./tester/map.sh
stack		:
			@bash ./tester/stack.sh

clean		:
			rm -f ${OBJS}

cleantest	:
			rm -f std_map std_vector std_stack ft_map ft_vector ft_stack *.txt

fclean		:
			rm -f ${OBJS} ${NAME}

re		:	fclean all

.PHONY		:	all vector map stack clean cleantest fclean re
