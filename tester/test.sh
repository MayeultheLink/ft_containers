c++ -DNAMESPACE=ft -o ft_vector main_vector.cpp
c++ -DNAMESPACE=std -o std_vector main_vector.cpp
c++ -DNAMESPACE=ft -o ft_map main_map.cpp
c++ -DNAMESPACE=std -o std_map main_map.cpp

./ft_vector > ft_vector.txt
./std_vector > std_vector.txt
./ft_map > ft_map.txt
./std_map > std_map.txt
diff ft_vector.txt std_vector.txt
diff ft_map.txt std_map.txt
