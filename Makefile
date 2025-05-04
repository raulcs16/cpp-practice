# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and object files
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# Output executable name
TARGET = main

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

