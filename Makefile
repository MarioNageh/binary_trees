CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
SRCS =  tests/8-main.c $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
FOLDER = outputs
TARGET = $(FOLDER)/1-left

all: $(TARGET) clean run

$(TARGET): $(OBJS)
	@echo "Removing old $(TARGET)"
	@rm -f $(TARGET)
	$(CC) -g $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

run:
	@echo "Running $(TARGET)"
	@./$(TARGET)	

val:
	@echo "Running valgrind on $(TARGET)"
	@rm -f vgcore.*
	@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(TARGET)

bet:
	@echo "Running betty on $(SRCS)"
	@betty $(SRCS)

.PHONY: all clean
