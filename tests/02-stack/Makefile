#Makefile stack

TARGET = Stack
#TARGET2 = Queue

CC = g++
CFLAGS = -g -pedantic -Wall -std=c++17 
PATH_SRC = ../../src/
PATH_INC = ../../inc/

check:$(TARGET)
	./$(TARGET)

$(TARGET): main.cpp $(PATH_SRC)$(TARGET).cpp $(PATH_INC)$(TARGET).hpp
	$(CC) $(CFLAGS) -I $(PATH_INC) $(PATH_SRC)$(TARGET).cpp  main.cpp -o $(TARGET)
	
#$(TARGET2): main.cpp $(PATH_SRC)$(TARGET2).cpp $(PATH_INC)$(TARGET2).hpp	
#	$(CC) $(CFLAGS) -I $(PATH_INC) $(PATH_SRC)$(TARGET2).cpp $(PATH_SRC)$(TARGET).cpp main.cpp -o $(TARGET2)

valgrind:
	valgrind --log-file=valgrind.log --leak-check=full --track-origins=yes -s ./$(TARGET)
	
clean:
	rm -f $(TARGET) 

