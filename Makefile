TARGET = main

FLAGS = -std=c++17 -g

CFILES = $(wildcard *.c)
CXXFILES = $(wildcard *.cpp)

OBJFILES = $(CFILES:.c=.o) $(CXXFILES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJFILES)
	g++ -o $@ $^ $(FLAGS)

%.o: %.cpp
	g++ -o $@ -c $^ $(FLAGS)

%.o: %.c
	gcc -o $@ -c $^ $(FLAGS)

clean:
	rm -f $(TARGET) $(OBJFILES)