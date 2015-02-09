CC = g++
CFLAGS 	= -c -Wall -O3 -fPIC -I ./include/ -std=c++11
LDFLAGS = 

#Include Libs
#include OpenCV
CFLAGS 		+= $(shell pkg-config opencv --cflags) 
LDFLAGS 	+= $(shell pkg-config opencv --libs)


SOURCES		= $(wildcard ./src/*.cpp)

OBJECTS		= $(SOURCES:.cpp=.o)

EXECUTABLE 	= particle_filter.bin

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(CURDIR)/$< -o $@

clean: 
	rm -rf ./src/*.o $(EXECUTABLE)

















