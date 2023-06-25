SOURCES = src/list.cc
FLAG = -Wall -Werror -Wextra -g

test: gtest_install
	cd test && cmake -S . -B build
	cd test && cmake --build build
	cd test/build && ctest --rerun-failed --output-on-failure

list.a:
	g++ -c $(FLAG) $(SOURCES)
	ar rcs list.a list.o
	rm -rf list.o

main: main.o list.a
	g++ -o  main_test $(FLAG) main.o list.a
	./main_test

main.o: main.cc
	g++ -c $(FLAG) main.cc

gtest_install:
	if test ! -d googletest; \
	then \
	`git clone https://github.com/google/googletest.git -b v1.13.0`; \
	cd googletest; cmake -B build googletest/build ..; \
	fi

coverage: test
	mkdir report 
	gcovr --verbose --html-details report/coverage.html -r src .

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=_valgrind_res.txt ./test/build/ListTests

clean:
	rm -rf  *.o *.a main_test test/build _valgrind_res.txt report
