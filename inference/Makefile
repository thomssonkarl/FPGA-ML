CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11
LDFLAGS = -lm

SOURCES = inference_double.c inference_fixed.c dot_product.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLES = inference_double inference_fixed

.PHONY: all clean fixed double

all: $(EXECUTABLES)

inference_double: inference_double.o
	$(CC) -o $@ $^ $(LDFLAGS)

inference_fixed: inference_fixed.o dot_product.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

fixed: inference_fixed

double: inference_double

clean:
	rm -f $(OBJECTS) $(EXECUTABLES)

