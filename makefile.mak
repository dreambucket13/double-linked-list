# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -g

  # the build target executable:
TARGET = DLList
DEBUG = -debug
DIR := ${CURDIR}

#syntax is, in order to this: I need these up to date
#command is on next line with a tab (not 5 spaces!!)

all: $(TARGET)

$(TARGET): $(TARGET).c 
	$(CC) -o $(TARGET) $(TARGET).c $(CFLAGS)

debug: $(TARGET)-debug

$(TARGET)-debug: $(TARGET).c 
	$(CC) -o $(TARGET)-debug $(TARGET).c $(CFLAGS) -DDEBUG


#windows clean
clean:
	rm $(DIR)/*.exe


