c++ -DNAMESPACE=ft -o ft maintester.cpp
c++ -DNAMESPACE=std -o std maintester.cpp

./ft > ft.txt
./std > std.txt
diff ft.txt std.txt
