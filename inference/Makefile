CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

SOURCES = inference_double.c inference_fixed.c
OBJECTS = $(SOURCES:.c=.o)
	EXECUTABLE = inference_double inference_fixed

.PHONY: all clean fixed double

all: $(EXECUTABLE)

inference_double: inference_double.o
	$(CC) $(LDFLAGS) -o $@ $^

inference_fixed: inference_fixed.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

fixed: inference_fixed

double: inference_double

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

