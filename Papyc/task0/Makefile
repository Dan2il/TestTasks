SOURCES = list.cc
FLAG = -Wall -Werror -Wextra -g

list.a:
	g++ -c $(FLAG) $(SOURCES)
	ar rcs list.a list.o
	rm -rf list.o

main: main.o list.a
	g++ -o  main_test $(FLAG) main.o list.a
	./main_test

main.o: main.cc
	g++ -c $(FLAG) main.cc

clean:
	rm -rf  *.o *.a main_test
