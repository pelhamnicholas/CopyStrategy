CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -Wall -Werror -ansi -pedantic

all: lab08

lab08: $(OBJ_FILES)
	mkdir -p bin
	g++ -o bin/$@ $^

obj/%.o: src/%.cpp
	mkdir -p obj
	g++ $(CC_FLAGS) -c -o $@ $<

debug: $(OBJ_FILES)
	g++ -g $(CC_FLAGS) -o $@ $^

clndbg:
	rm debug
	rm -r obj

clean:
	rm -r bin
	rm -r obj
