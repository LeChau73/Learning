# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -g -std=c++11
TARGET := outDebug

# Object files
OBJS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: $(TARGET)

# Rule to compile each .cpp file to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link all object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean
