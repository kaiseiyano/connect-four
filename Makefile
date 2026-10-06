CC = cc
CFLAGS = -Wall -Wextra

# picks up main.c plus every feature folder (player/, board/, ...) automatically
SRCS = main.c $(wildcard */*.c)
HDRS = $(wildcard */*.h)
TARGET = connect-four

$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
