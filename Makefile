CC      := gcc
CFLAGS  := -Wall -Wextra -Wpedantic -O2 -Iinclude
LDFLAGS :=

TARGET  := build/gerenciador.exe
SRC     := $(wildcard src/*.c)
OBJ     := $(patsubst src/%.c,build/%.o,$(SRC))

.PHONY: all run clean

all: $(TARGET)

# cria a pasta build (se não existir)
build:
	@mkdir -p build

# link final (gera o .exe)
$(TARGET): build $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# compila cada .c em .o
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	@rmdir /S /Q build 2>NUL || true
