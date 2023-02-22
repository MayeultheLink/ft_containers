c++ -Werror -Wextra -Wall -std=c++98 -DNAMESPACE=ft -o ft_vector ../main_vector.cpp
c++ -Werror -Wextra -Wall -std=c++98 -DNAMESPACE=std -o std_vector ../main_vector.cpp

./ft_vector > ft_vector.txt
./std_vector > std_vector.txt
diff ft_vector.txt std_vector.txt
