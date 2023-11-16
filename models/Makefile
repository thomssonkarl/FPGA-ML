CC := g++
CFLAGS := -Wall -std=c++11
SRCS := network.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := network

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp network.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

