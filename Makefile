CC=g++
CFLAGS=-Wall -std=c++11 -lpistache -lpthread -O3
OBJECTS=main.o server/handler.o
TARGET=run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGET)

%.o: %.cpp
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	rm -rf $(TARGET) $(OBJECTS)