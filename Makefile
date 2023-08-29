CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
SRCS = binary_tree_print.c tests/0-main.c 0-binary_tree_node.c
OBJS = $(SRCS:.c=.o)
TARGET = 0-node

all: $(TARGET) clean

$(TARGET): $(OBJS)
	@echo "Removing old $(TARGET)"
	@rm -f $(TARGET)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: all clean
