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



$(TARGET): utest.o $(SRC_DIR)Game.o $(SRC_DIR)Board.o $(SRC_DIR)Ball.o $(SRC_DIR)Bar.o -lsfml-graphics -lsfml-window -lsfml-system

utest.o: utest.cpp $(INC_DIR)Game.hpp $(INC_DIR)MoveShape.hpp $(INC_DIR)Board.hpp $(INC_DIR)Ball.hpp $(INC_DIR)Bar.hpp

$(SRC_DIR)Game.o: $(INC_DIR)Game.hpp $(SRC_DIR)Game.cpp
$(SRC_DIR)Board.o: $(INC_DIR)Board.hpp $(SRC_DIR)Board.cpp 
$(SRC_DIR)Ball.o: $(INC_DIR)Ball.hpp $(SRC_DIR)Ball.cpp
$(SRC_DIR)Bar.o: $(INC_DIR)Bar.hpp $(SRC_DIR)Bar.cpp


valgrind:$(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=val.txt ./$(TARGET)

clean:
	@$(RM) *.o *.d $(SRC_DIR)*.o  $(SRC_DIR)*.d $(TARGET) $(DEPENDS)*.d *.ppm

DEPENDS = $(utest.o:%.o=%.d)
	-include $(DEPENDS)
	
	
