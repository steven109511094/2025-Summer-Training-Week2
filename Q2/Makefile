.PHONY: all clean

# Compiler settings
CXX = g++
CXXFLAGS = -I ./inc -std=c++11
WARNINGS = -g -Wall

# Valgrind for memory issue
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 

# Source files and object files
SRCDIR = src
OBJDIR = obj
INCDIR = inc
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Name of the executable
TARGET = myStack myQueue

all: $(TARGET)

$(OBJDIR):
	@mkdir $(OBJDIR)

myStack: myStack.cpp $(OBJS)
	$(CXX) $(WARNINGS) $(CXXFLAGS) $^ -o $@

myQueue: myQueue.cpp $(OBJS)
	$(CXX) $(WARNINGS) $(CXXFLAGS) $^ -o $@

# Compilation rule for object files with automatic dependency generation
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR) Makefile
	$(CXX) $(WARNINGS) $(CXXFLAGS) -c $< -o $@

run:
	./myStack
	./myQueue

check:
	$(CHECKCC) $(CHECKFLAGS) ./myStack
	$(CHECKCC) $(CHECKFLAGS) ./myQueue

clear: 
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f output/myStack/*
	rm -f output/myQueue/*
	
