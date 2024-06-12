include lib.mk
CC = gcc
BUILD_DIR = build
BIN_DIR = bin
src_path := $(shell pwd) $(SIR)
SRC_FILES = $(foreach dir, $(src_path), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TARGET = $(BIN_DIR)/app
all: $(TARGET)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)