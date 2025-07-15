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

check_stack_ans:
	chmod +x gen_stack_golden
	./gen_stack_golden
	chmod +x script/check_stack_ans.sh
	bash ./script/check_stack_ans.sh

check_queue_ans:
	chmod +x gen_queue_golden
	./gen_queue_golden
	chmod +x script/check_queue_ans.sh
	bash ./script/check_queue_ans.sh

check_stack_mem:
	$(CHECKCC) $(CHECKFLAGS) ./myStack

check_queue_mem:
	$(CHECKCC) $(CHECKFLAGS) ./myQueue

gen_pattern: gen_pattern.cpp
	$(CXX) $(WARNINGS) $(CXXFLAGS) $^ -o $@
	./$@

clear: 
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f gen_pattern
	rm -f output/myStack/*
	rm -f output/myQueue/*
	
