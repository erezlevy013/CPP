#CXX=clang++-12
CC=$(CXX)

SRC_DIR = ../../src/
INC_DIR = ../../inc/

CPPFLAGS = -I$(INC_DIR)
CXXFLAGS = -std=c++17
CXXFLAGS+= -g -pedantic -Wall -Werror

TARGET = utest

check: $(TARGET)
	./$(TARGET) -v



$(TARGET): utest.o $(SRC_DIR)Token.o $(SRC_DIR)Lexer.o $(SRC_DIR)Number.o $(SRC_DIR)Parser.o $(SRC_DIR)Func.o $(SRC_DIR)Add.o $(SRC_DIR)Sub.o $(SRC_DIR)Div.o $(SRC_DIR)Mul.o $(SRC_DIR)Pow.o $(SRC_DIR)Modulo.o $(SRC_DIR)Var.o

utest.o: utest.cpp Number.o $(INC_DIR)Exper.hpp $(INC_DIR)Number.hpp $(INC_DIR)Func.hpp $(INC_DIR)Add.hpp $(INC_DIR)Sub.hpp $(INC_DIR)Div.hpp $(INC_DIR)Mul.hpp $(INC_DIR)Pow.hpp $(INC_DIR)Modulo.hpp $(INC_DIR)Var.hpp

$(SRC_DIR) Token.o: $(SRC_DIR)Token.cpp $(INC_DIR)Token.hpp
$(SRC_DIR) Lexer.o: $(SRC_DIR)Lexer.cpp $(INC_DIR)Lexer.hpp
$(SRC_DIR) Number.o: $(SRC_DIR)Number.cpp $(INC_DIR)Number.hpp 
$(SRC_DIR) Parser.o: $(SRC_DIR)Parser.cpp $(INC_DIR)Parser.hpp

$(SRC_DIR)Func.o: $(SRC_DIR)Func.cpp $(INC_DIR)Func.hpp
$(SRC_DIR) Add.o: $(SRC_DIR)Add.cpp $(INC_DIR)Add.hpp 
$(SRC_DIR) Sub.o: $(SRC_DIR)Sub.cpp $(INC_DIR)Sub.hpp 
$(SRC_DIR) Div.o: $(SRC_DIR)Div.cpp $(INC_DIR)Div.hpp
$(SRC_DIR) Mul.o: $(SRC_DIR)Mul.cpp $(INC_DIR)Mul.hpp
$(SRC_DIR)Pow.o: $(SRC_DIR)Pow.cpp $(INC_DIR)Pow.hpp
$(SRC_DIR)Modulo.o: $(SRC_DIR)Modulo.cpp $(INC_DIR)Modulo.hpp 
$(SRC_DIR)Var.o: $(SRC_DIR)Var.cpp $(INC_DIR)Var.hpp


valgrind:$(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=val.txt ./$(TARGET)

clean:
	@$(RM) *.o $(SRC_DIR)*.o  $(TARGET)

