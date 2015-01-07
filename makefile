headers := $(wildcard inc/*.h)
sources := $(wildcard src/*.cpp)
#objects := $(patsubst %.cpp, %.o, $(notdir $(sources)))
objects := $(addprefix obj/, $(patsubst %.cpp,%.o,$(notdir $(sources))))

CC := g++
CFLAGS := -Wall -O3
TARGET := bin/Scheck

all: $(TARGET)

$(TARGET): $(objects)
	$(CC) -I inc $(objects) -o $(TARGET)

obj/%.o: src/%.cpp | dirs
	$(CC) -I inc $(CFLAGS) -c $< -o $@

dirs:
	-@mkdir -p obj
	-@mkdir -p bin

clean:
	-rm obj/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)