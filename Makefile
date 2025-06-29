
SRC_DIR = src

CC = gcc
CFLAGS = -Iinclude `pkg-config --cflags sdl2 SDL2_image`
LDFLAGS = `pkg-config --libs sdl2 SDL2_image`

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
TARGET = vnfv

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean