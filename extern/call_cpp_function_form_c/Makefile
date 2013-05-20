all:
	g++ -c -Wall -Werror -fPIC cppfile.cpp
	g++ -shared -o libcppfile.so cppfile.o
	gcc -L./ -Wall main.c -o main.bin -lcppfile
	export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
