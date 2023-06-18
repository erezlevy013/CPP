#CXX=clang++-12
CC=$(CXX)

SRC_DIR = ../../src/
INC_DIR = ../../inc/

CPPFLAGS = -I$(INC_DIR)
CXXFLAGS = -std=c++17
CXXFLAGS+= -pedantic -Wall -Werror

TARGET = utest

check: $(TARGET)
	./$(TARGET) -v



$(TARGET): utest.o

utest.o: utest.cpp $(INC_DIR)Iter.hpp


valgrind:$(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=val.txt ./$(TARGET)

clean:
	@$(RM) *.txt *.o $(SRC_DIR)*.o  $(TARGET)

