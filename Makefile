CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable

PROGRAM_NAME = note
BUILD_DIR = build/
BUILD_BIN = $(BUILD_DIR)$(PROGRAM_NAME)
SRCS = \
	src/main.c \
	src/program.c

.PHONY: all build clean

all: build

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(BUILD_BIN)

clean:
	rm -rf $(BUILD_DIR)*
