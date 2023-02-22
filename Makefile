NAME		=	ft_containers

SRCS		=	srcs/main.cpp
SRCS_V		=	srcs/main_vector.cpp
SRCS_M		=	srcs/main_map.cpp
SRCS_S		=	srcs/main_stack.cpp

CC		=	c++
CFLAGS		=	-Wall -Wextra -Werror -I./headers -std=c++98
OBJS		=	${SRCS:.cpp=.o}
DEPS		=	${OBJS:.o=.d}

all		:	${NAME}

-include $(DEPS)

$(NAME)		:	$(OBJS)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

vector		:	
			${CC} ${CFLAGS} ${SRCS_V} -o ft_vector -DNAMESPACE=ft
			${CC} ${CFLAGS} ${SRCS_V} -o std_vector -DNAMESPACE=std
			./ft_vector > ft_vector.txt && ./std_vector > std_vector.txt
			diff ft_vector.txt std_vector.txt

map		:
			${CC} ${CFLAGS} ${SRCS_M} -o ft_map -DNAMESPACE=ft
			${CC} ${CFLAGS} ${SRCS_M} -o std_map -DNAMESPACE=std
			./ft_map > ft_map.txt && ./std_map > std_map.txt
			diff ft_map.txt std_map.txt

stack		:
			${CC} ${CFLAGS} ${SRCS_S} -o ft_stack -DNAMESPACE=ft
			${CC} ${CFLAGS} ${SRCS_S} -o std_stack -DNAMESPACE=std
			./ft_stack > ft_stack.txt && ./std_stack > std_stack.txt
			diff ft_stack.txt std_stack.txt

%.o:%.cpp		
			$(CC) -MMD $(CFLAGS) -c $< -o $@

clean		:
			rm -f ${OBJS} ${DEPS}

cleantest	:
			rm -f std_map std_vector std_stack ft_map ft_vector ft_stack *.txt

fclean		:
			rm -f ${OBJS} ${NAME}

re		:	fclean all

.PHONY		:	all vector map stack clean cleantest fclean re
