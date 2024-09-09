CXX = g++
CXXFLAGS = -Wall -g -Iinc -std=c++17

SRC_DIR = src
MISC_DIR = misc
INC_DIR = inc

ASSEMBLER_SRCS = $(filter-out $(SRC_DIR)/emulator.cpp $(SRC_DIR)/linker.cpp, $(wildcard $(SRC_DIR)/*.cpp))
EMULATOR_SRCS = $(SRC_DIR)/emulator.cpp
LINKER_SRCS = $(SRC_DIR)/linker.cpp
C_SRCS = $(wildcard $(MISC_DIR)/*.c)

ASSEMBLER_OBJS = $(ASSEMBLER_SRCS:.cpp=.o) $(C_SRCS:.c=.o) $(MISC_DIR)/flex.o $(MISC_DIR)/parser.o

ASSEMBLER_TARGET = assembler
EMULATOR_TARGET = emulator
LINKER_TARGET = linker

all: $(ASSEMBLER_TARGET) $(EMULATOR_TARGET) $(LINKER_TARGET)

$(ASSEMBLER_TARGET): $(ASSEMBLER_OBJS)
	$(CXX)	$(CXXFLAGS) -o $@ $^
	rm -f $(ASSEMBLER_OBJS)

$(EMULATOR_TARGET): $(EMULATOR_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(LINKER_TARGET): $(LINKER_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(MISC_DIR)/%.o: $(MISC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(MISC_DIR)/flex.c: $(MISC_DIR)/flex.l $(MISC_DIR)/bison.h
	flex -o $@ $<

$(MISC_DIR)/flex.o: $(MISC_DIR)/flex.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(MISC_DIR)/parser.o: $(MISC_DIR)/bison.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(MISC_DIR)/bison.c $(MISC_DIR)/bison.h: $(MISC_DIR)/bisonFile.y
	bison -d -o $(MISC_DIR)/bison.c $<

clean:
	rm -f misc/*.o src/*.o misc/flex.c misc/bison.c misc/bison.h $(ASSEMBLER_TARGET) $(EMULATOR_TARGET) $(LINKER_TARGET)

.PHONY: all clean