GTEST_DIR = /usr/local 
GTEST_LIB = $(GTEST_DIR)/lib/libgtest.a
GTEST_INCLUDE = -I$(GTEST_DIR)/include

all :MAIN TEST
MAIN :main.o quick_sort.o
	g++ -Wall -o MAIN main.o quick_sort.o
TEST :test.o quick_sort.o
	g++ -Wall -o TEST test.o quick_sort.o $(GTEST_LIB) -lpthread
main.o :main.cpp quick_sort.h
	g++ -Wall -c main.cpp
test.o :test.cpp quick_sort.h
	g++ -Wall -c test.cpp
quick_sort.o :quick_sort.cpp quick_sort.h
	g++ -Wall -c quick_sort.cpp
clean :
	rm *.o MAIN TEST