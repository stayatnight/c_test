include lib.mk
#CC = gcc
CC=clang
BUILD_DIR = build
BIN_DIR = bin
#LDFLAGS=WL
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
size:
	@echo "***************************build sucess*************************************************"
	@echo "Size of $(TARGET):"
	@stat -c%s "$(TARGET)"
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)