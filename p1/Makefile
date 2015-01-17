funix.out:funix.o main.o directory.o permissions.o
	g++ -g -Wall -ansi -o funix.out funix.o main.o directory.o
funix.o:funix.cpp funix.h
	g++ -g -Wall -ansi -c funix.cpp
main.o:main.cpp funix.h
	g++ -g -Wall -ansi -c main.cpp
directory.o:directory.cpp directory.h
	g++ -g -Wall -ansi -c directory.cpp
permissions.o:permissions.cpp permissions.h  
	g++ -g -Wall -ansi -c permissions.cpp
clean:
	rm -f funix.o main.o directory.o funix.out permissions.o
