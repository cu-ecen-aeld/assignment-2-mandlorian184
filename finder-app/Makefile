# Set the target architecture (for cross-compilation, it's ARM64)
TARGET_ARCH = aarch64

# Check if CROSS_COMPILE is set, otherwise default to the native compiler
CC = gcc
CFLAGS = -Wall -g

# If CROSS_COMPILE is set, use the cross-compiler tools (e.g., aarch64-none-linux-gnu-)
ifeq ($(CROSS_COMPILE),)
    # Native compilation (use default tools)
    COMPILE_CC = $(CC)
else
    # Cross-compilation using aarch64 toolchain
    COMPILE_CC = $(CROSS_COMPILE)gcc
endif

# The target executable
TARGET = writer

# Source files
SRC = writer.c

# Object files (converted from .c files)
OBJ = $(SRC:.c=.o)

# Default rule to build the target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(COMPILE_CC) -o $@ $(OBJ)

# Rule to compile .c files to .o (object files)
%.o: %.c
	$(COMPILE_CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

# Print the toolchain used
print-toolchain:
	@echo "Using compiler: $(COMPILE_CC)"
