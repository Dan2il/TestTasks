SOURCES = src/list.cc
FLAG = -Wall -Werror -Wextra -g

main: 
	g++ $(FLAG) -c main.cc 
	g++ -o  main_test $(FLAG) main.o
	./main_test

clean:
	rm -rf  *.o main_test
