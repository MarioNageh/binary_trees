CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
SRCS = tests/1-main.c 0-binary_tree_node.c binary_tree_print.c 1-binary_tree_insert_left.c
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
