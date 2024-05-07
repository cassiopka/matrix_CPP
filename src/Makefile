CC = g++ -lstdc++
SRC = my_matrix_oop.cc
OBJ_OOP_O = my_matrix_oop.o
OBJ_TEST_O = my_matrix_test.o
ARCHIVER_OOP = my_matrix_oop.a
ARCHIVER_TEST = my_matrix_test.a
FLAGS= -Wall -Werror -Wextra -std=c++17
TESTFLAGS=-lgtest

SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Linux)
    # Код для компиляции под Linux
	OPEN_CMD = xdg-open
else ifeq ($(SYSTEM), Darwin)
    # Код для компиляции под macOS
	OPEN_CMD = open
else
    $(error Unsupported system: $(SYSTEM))
endif


all: gcov_report

gcov_report: clean my_matrix_test.a
	$(CC) -coverage $(SRC) $(ARCHIVER_TEST) -o my_matrix_oop.out $(TESTFLAGS)
	./my_matrix_oop.out
	lcov -t "my_matrix_oop" -o my_matrix_oop.info -c -d ./ --no-external 
	genhtml -o report my_matrix_oop.info
	$(OPEN_CMD) report/index.html

test: clean my_matrix_oop.a
	$(CC) $(FLAGS) my_matrix_test.cc $(ARCHIVER_OOP) -o my_matrix_oop.out $(TESTFLAGS)
	./my_matrix_oop.out

my_matrix_oop.a:
	$(CC) -c $(FLAGS) $(SRC) -o $(OBJ_OOP_O)
	ar -rcs $(ARCHIVER_OOP) $(OBJ_OOP_O)

my_matrix_test.a:
	$(CC) -c $(FLAGS) my_matrix_test.cc -o $(OBJ_TEST_O)
	ar -rcs $(ARCHIVER_TEST) $(OBJ_TEST_O)

clean:
	rm -rf *.out *.o *.gcno *.info my_matrix_oop.a *.gcda *.a *.o
	-rm -rf report

leaks:
	leaks --atExit -- ./my_matrix_oop.out
	