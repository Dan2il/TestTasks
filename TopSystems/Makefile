FLAGS = -Werror -Wall -Wextra -std:c++17

build:
	g++ -c main.cpp source/painter.cpp
	g++ main.o painter.o -o painter -lsfml-graphics -lsfml-window -lsfml-system
	./painter

clean:
	rm -rf *.o painter