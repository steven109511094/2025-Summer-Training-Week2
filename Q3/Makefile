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
TARGET = myLinkedList

all: $(TARGET)

$(OBJDIR):
	@mkdir $(OBJDIR)

myLinkedList: myLinkedList.cpp $(OBJS)
	$(CXX) $(WARNINGS) $(CXXFLAGS) $^ -o $@

# Compilation rule for object files with automatic dependency generation
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR) Makefile
	$(CXX) $(WARNINGS) $(CXXFLAGS) -c $< -o $@

run:
	./myLinkedList

check_ans:
	chmod +x gen_golden
	./gen_golden
	chmod +x script/check_ans.sh
	bash ./script/check_ans.sh

check_mem:
	$(CHECKCC) $(CHECKFLAGS) ./myLinkedList

gen_pattern: gen_pattern.cpp
	$(CXX) $(WARNINGS) $(CXXFLAGS) $^ -o $@
	./$@

clear: 
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f gen_pattern
	rm -f output/*
	
