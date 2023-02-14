c++ -Werror -Wextra -Wall -DNAMESPACE=ft -o ft_vector main_vector.cpp
c++ -Werror -Wextra -Wall -DNAMESPACE=std -o std_vector main_vector.cpp

./ft_vector > ft_vector.txt
./std_vector > std_vector.txt
diff ft_vector.txt std_vector.txt
