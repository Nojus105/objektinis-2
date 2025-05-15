CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17
DLLFLAGS = -shared -fPIC

VECTOR_SRCS = $(wildcard vector/*.cpp)
TEST_SRCS = $(wildcard test/*.cpp)

BIN_DIR = bin
DLL_NAME = $(BIN_DIR)/vector_library.dll

all: $(DLL_NAME) $(BIN_DIR)/vector_program

$(BIN_DIR):
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Build the DLL
$(DLL_NAME): vector/functions.cpp vector/dll_header.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(DLLFLAGS) -o $@ vector/functions.cpp

# Build the main program, dynamically linking to the DLL
$(BIN_DIR)/vector_program: $(VECTOR_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(VECTOR_SRCS) -L$(BIN_DIR) -lvector_library

test: $(BIN_DIR)/test_program

$(BIN_DIR)/test_program: test/test.cpp vector/functions.cpp test/catch.hpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ test/test.cpp vector/functions.cpp

clean:
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)