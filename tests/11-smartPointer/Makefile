CXX?=g++ 
CC=$(CXX)


CPPFLAGS = -MMD -MP
CXXFLAGS = -std=c++17
CXXFLAGS+= -pedantic -Wall -Werror

TARGET = smartPointer

check: $(TARGET)
	./$(TARGET)



$(TARGET): smartPointer.o

smartPointer.o: smartPointer.cpp 


valgrind:$(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=val.txt ./$(TARGET)

clean:
	@$(RM) *.o $(SRC_DIR)*.o  $(TARGET) smartPointer.d

