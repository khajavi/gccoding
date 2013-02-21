LIBS = `pkg-config gtkmm-3.0 --cflags --libs`

all: examplewindow.o main.o
	g++ $(LIBS) examplewindow.o main.o -o main.bin

examplewindow.o: examplewindow.h examplewindow.cpp
	g++ $(LIBS) -c examplewindow.cpp -o examplewindow.o

main.o: main.cpp
	g++ $(LIBS) -c main.cpp -o main.o
