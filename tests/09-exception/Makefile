CXX?=g++
CC=$(CXX)

SRC_DIR = ../../src/
INC_DIR = ../../inc/

CPPFLAGS = -MMD -MP -I$(INC_DIR)
CXXFLAGS = -std=c++17
CXXFLAGS+= -g -pedantic -Wall -Werror

TARGET = utest

check: $(TARGET)
	./$(TARGET) -v



$(TARGET): utest.o $(SRC_DIR)Pixel.o $(SRC_DIR)Point.o

utest.o: utest.cpp $(INC_DIR)DoubleBuffer.hpp $(INC_DIR)MyException.hpp $(INC_DIR)Point.hpp $(INC_DIR)Pixel.hpp $(INC_DIR)Shape.hpp $(INC_DIR)Line.hpp $(INC_DIR)Box.hpp 

$(SRC_DIR) Pixel.o: $(INC_DIR)Pixel.hpp $(SRC_DIR)Pixel.cpp
$(SRC_DIR) Point.o: $(INC_DIR)Point.hpp $(SRC_DIR)Point.cpp


valgrind:$(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=val.txt ./$(TARGET)

clean:
	@$(RM) *.o *.d $(SRC_DIR)*.o  $(SRC_DIR)*.d $(TARGET) $(DEPENDS)*.d *.ppm

DEPENDS = $(utest.o:%.o=%.d)
	-include $(DEPENDS)


