CC = cc
CFLAGS = -Wall -Wextra

# picks up src/main.c plus every feature folder (src/player/, src/board/, ...) automatically
SRCS = $(wildcard src/*.c src/*/*.c)
HDRS = $(wildcard src/*/*.h)
TARGET = connect-four

$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
