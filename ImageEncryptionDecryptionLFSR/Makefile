CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic
SFFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic $(SFFLAGS)

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	$(CC) -c PhotoMagic.cpp LFSR.hpp $(CFLAGS)

LFSR.o: LFSR.hpp LFSR.cpp
	$(CC) -c LFSR.cpp $(CFLAGS)

clean:
	rm *.o
	rm PhotoMagic
