# Makefile for Expense Tracker

# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -I include -std=c++11

# Target executable name
TARGET = Expense_Tracker

# Source directory
SRC_DIR = src

# Object files directory
OBJ_DIR = obj

# Test directory
TEST_DIR = tests

# Google Test directory
GTEST_DIR = /usr/src/googletest/build/lib

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Test source files (exclude main.cpp from the test build)
TEST_SOURCES = $(filter-out $(SRC_DIR)/main.cpp, $(SOURCES)) $(wildcard $(TEST_DIR)/*.cpp)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Test object files
TEST_OBJECTS = $(TEST_SOURCES:%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# To obtain object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Special rule for test source files from the TEST_DIR
$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test target
test: $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o test $^ -L$(GTEST_DIR) -lgtest -lgtest_main -pthread
	./test

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(TARGET) test

# PHONY targets
.PHONY: all clean test

