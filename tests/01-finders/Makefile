#Makefile finders

TARGET = finders
CC = g++
CFLAGS = -ansi -g -pedantic -std=c++11 
PATH1 = ../../src/
PATH2 = ../../inc/

$(TARGET): main.cpp $(PATH1)$(TARGET).cpp $(PATH2)$(TARGET).hpp
	$(CC) $(CFLAGS) main.cpp $(PATH1)$(TARGET).cpp -o $(TARGET)
	

clean:
	rm -f $(TARGET) 
