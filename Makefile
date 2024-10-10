CC = gcc

CFLAGS = -Wall -Wextra -std=c99

TARGET = test

SRCS = test.c lib_ppm.c

OBJS = $(SRCS:.c=.o)

HEADERS = lib_ppm.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJS) $(TARGET).exe

.PHONY: all clean