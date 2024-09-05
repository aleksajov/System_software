# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -Iinc

# Directories
SRC_DIR = src
MISC_DIR = misc
INC_DIR = inc

# Source files
CPP_SRCS = $(wildcard $(SRC_DIR)/*.cpp)
C_SRCS = $(wildcard $(MISC_DIR)/*.c)
OBJS = $(CPP_SRCS:.cpp=.o) $(C_SRCS:.c=.o) $(MISC_DIR)/lexer.o $(MISC_DIR)/parser.o

# Output executable
TARGET = asembler

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm -f $(OBJS)

# Compile .cpp source files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX)	$(CXXFLAGS) -c -o $@ $<

# Compile .c source files
$(MISC_DIR)/%.o: $(MISC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<



# Generate the lexer
$(MISC_DIR)/lexer.c: $(MISC_DIR)/flex.l $(MISC_DIR)/bisonFile.tab.h
	flex -o $@ $<

# Compile the lexer
$(MISC_DIR)/lexer.o: $(MISC_DIR)/lexer.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile the parser
$(MISC_DIR)/parser.o: $(MISC_DIR)/bisonFile.tab.c
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Generate the parser
$(MISC_DIR)/bisonFile.tab.c $(MISC_DIR)/bisonFile.tab.h: $(MISC_DIR)/bisonFile.y
	bison -d -o $(MISC_DIR)/bisonFile.tab.c $<

# Clean up build files
clean:
	rm -f misc/*.o src/*.o misc/lexer.c misc/bisonFile.tab.c misc/bisonFile.tab.h asembler 

# Run the program with GDB
gdb: $(TARGET)
	gdb $(TARGET)

# Phony targets
.PHONY: all clean gdb
