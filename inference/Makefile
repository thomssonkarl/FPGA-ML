CC = gcc
CFLAGS = -Wall -Wextra -std=c11 
LDFLAGS = -lm

SOURCES = inference.c 
OBJECTS = $(SOURCES:.c=.o)
	EXECUTABLE = inference

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

