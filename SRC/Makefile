CC=g++

INC_FLAGS= ../include

CFLAGS= -c -pedantic -Wall -Werror -Wconversion -ansi -g -I$(INC_FLAGS)
CXXFLAGS=$(CFLAGS)

TARGET = main
SOURCES=$(wildcard *.cpp)
OBJS = $(SOURCES:.cpp=.o)


$(TARGET): $(OBJS)

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)


.PHONY: clean run gdb leak

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends



clean:
	rm -f $(OBJS) $(TARGET) .depends
	
leak: $(TARGET)
	 valgrind --leak-check=full ./$(TARGET)
