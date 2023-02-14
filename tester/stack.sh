c++ -Werror -Wextra -Wall -DNAMESPACE=ft -o ft_stack main_stack.cpp
c++ -Werror -Wextra -Wall -DNAMESPACE=std -o std_stack main_stack.cpp

./ft_stack > ft_stack.txt
./std_stack > std_stack.txt
diff ft_stack.txt std_stack.txt
