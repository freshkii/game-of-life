CXX = g++
CC = gcc

TARGET = bin

SRC_DIR = ./src
BUILD_DIR = ./build

SRCS = $(shell find $(SRC_DIR) -name "*.cpp") 
OBJS = $(SRCS:%=$(BUILD_DIR)/%.o)

GLAD_SRC = ./$(SRC_DIR)/glad.c
GLAD_OBJ = $(BUILD_DIR)/$(GLAD_SRC).o

CFLAGS = $(shell pkg-config --cflags glfw3 gl)
LDFLAGS = $(shell pkg-config --libs glfw3 gl) 

$(BUILD_DIR)/$(TARGET): $(OBJS) $(GLAD_OBJ)
	$(CXX) $(OBJS) $(GLAD_OBJ) -o $@ $(LDFLAGS)

$(GLAD_OBJ): $(GLAD_SRC)
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
