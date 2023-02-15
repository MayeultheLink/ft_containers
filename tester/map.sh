c++ -DNAMESPACE=ft -o ft_map main_map.cpp
c++ -DNAMESPACE=std -o std_map main_map.cpp

./ft_map > ft_map.txt
./std_map > std_map.txt
diff ft_map.txt std_map.txt
