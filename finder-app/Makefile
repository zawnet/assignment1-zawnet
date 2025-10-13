# Makefile for building the writer application

# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror

# Target executable
TARGET := writer
SRC := writer.c
OBJ := $(SRC:.c=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(TARGET) $(OBJ)