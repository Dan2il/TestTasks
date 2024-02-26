all: test

test: gtest_install
	cmake -S . -B build
	cmake --build build
	cd build && ctest --rerun-failed --output-on-failure

gtest_install:
	if test ! -d googletest; \
	then \
	`git clone https://github.com/google/googletest.git -b v1.13.0`; \
	cd googletest; cmake -B build googletest/build ..; \
	fi

gtest_uninstall:
	rm -rf googletest

coverage: test
	mkdir report 
	gcovr --html-details report/coverage.html -r matrix .

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=_valgrind_res.txt ./build/matrix_tests

style:
	clang-format -n *.*
	clang-format -n tests/*.*

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem s21_matrix_oop/

clean:
	rm -rf build report *.o *.a *.html *.css _valgrind_res.txt