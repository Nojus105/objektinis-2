CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

VECTOR_SRCS = $(wildcard vector/*.cpp)
TEST_SRCS = $(wildcard test/*.cpp)

BIN_DIR = bin

all: $(BIN_DIR)/vector_program

$(BIN_DIR):
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)

$(BIN_DIR)/vector_program: $(VECTOR_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(VECTOR_SRCS)

test: $(BIN_DIR)/test_program

$(BIN_DIR)/test_program: test/test.cpp vector/functions.cpp test/catch.hpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ test/test.cpp vector/functions.cpp

clean:
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)