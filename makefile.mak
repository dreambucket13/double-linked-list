# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -g

  # the build target executable:
TARGET = DLList

all: $(TARGET)

#syntax is, in order to this: I need these up to date
#command is on next line with a tab (not 5 spaces!!)
$(TARGET): $(TARGET).c 
	$(CC) -o $(TARGET) $(TARGET).c $(CFLAGS)
#windows clean
clean:
	-del -fR $(TARGET).exe

