CC = gcc
CFLAGS = -Wall  -Wextra -Iinclude
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TEST_DIR = tests
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.C=$(BUILD_DIR)/%.o)
EXEC = tests/N00bshell

all: $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC) $(TESTS_DIR)/main
