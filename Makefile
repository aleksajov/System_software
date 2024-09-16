CXX = g++
FLAGS = -Wall -g -Iinc -std=c++17

ASSEMBLER_SRCS = $(filter-out src/emulator.cpp src/linker.cpp, $(wildcard src/*.cpp))
EMULATOR_SRCS = src/emulator.cpp
LINKER_SRCS = src/linker.cpp
C_SRCS = $(wildcard misc/*.c)

ASSEMBLER_OBJS = $(ASSEMBLER_SRCS:.cpp=.o) $(C_SRCS:.c=.o) misc/flex.o misc/parser.o

ASSEMBLER_TARGET = assembler
EMULATOR_TARGET = emulator
LINKER_TARGET = linker

all: $(ASSEMBLER_TARGET) $(EMULATOR_TARGET) $(LINKER_TARGET)

$(ASSEMBLER_TARGET): $(ASSEMBLER_OBJS)
	$(CXX)	$(FLAGS) -o $@ $^
	rm -f $(ASSEMBLER_OBJS)

$(EMULATOR_TARGET): $(EMULATOR_SRCS)
	$(CXX) $(FLAGS) -o $@ $^

$(LINKER_TARGET): $(LINKER_SRCS)
	$(CXX) $(FLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

misc/%.o: misc/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

misc/flex.c: misc/flex.l misc/bison.hpp
	flex -o $@ $<

misc/flex.o: misc/flex.c
	$(CXX) $(FLAGS) -c $< -o $@

misc/parser.o: misc/bison.cpp
	$(CXX) $(FLAGS) -c $< -o $@

misc/bison.cpp misc/bison.hpp: misc/bisonFile.y
	bison -d -o misc/bison.cpp $<

clean:
	rm -f misc/*.o src/*.o misc/flex.c misc/bison.cpp misc/bison.hpp $(ASSEMBLER_TARGET) $(EMULATOR_TARGET) $(LINKER_TARGET)

.PHONY: all clean