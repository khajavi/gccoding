all:
	gcc -c -Wall -Werror -fPIC cfile.c
	gcc -shared -o libcfile.so cfile.o
	g++ -L/home/milad/source/github/gccoding/extern/call_c_function_from_cpp/ -Wall main.cpp -o main.bin -lcfile



