# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -fdiagnostics-color=always -std=c++20
DEBUG_FLAGS = -g -save-temps
RELEASE_FLAGS = -O3 -Ofast

# Source files
SRCS = $(wildcard *.cpp) $(wildcard ds/*.cpp) $(wildcard pc/*.cpp) $(wildcard beer_selector/*.cpp)

# Destination directory
MAIN_DEST = ../build
DEBUG_DEST = $(MAIN_DEST)/debug
RELEASE_DEST = $(MAIN_DEST)/release

# Object files
DEBUG_OBJS = $(patsubst %.cpp,$(DEBUG_DEST)/%.o,$(SRCS))
RELEASE_OBJS = $(patsubst %.cpp,$(RELEASE_DEST)/%.o,$(SRCS))

# Executable name
DEBUG_TARGET = $(DEBUG_DEST)/app
RELEASE_TARGET = $(RELEASE_DEST)/app

# Default target
all: debug release

# Debug target
debug: $(DEBUG_TARGET)

# Release target
release: $(RELEASE_TARGET)

# Debug target
$(DEBUG_DEST)/%.o: %.cpp
	mkdir -p `dirname $@`
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Release target
$(RELEASE_DEST)/%.o: %.cpp
	mkdir -p `dirname $@`
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c $< -o $@

# Link object files into executable
$(DEBUG_TARGET): $(DEBUG_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(RELEASE_TARGET): $(RELEASE_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -rf $(MAIN_DEST)