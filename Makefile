CC = g++
FLAGS = -c
LIBS = -lSDLmain -lSDL -lGL -lglut
SOURCES = main.cpp ball.cpp pongWorld.cpp player.cpp
HEADERS = headers.h globals.h ball.h pongWorld.h player.h
OBJECTS = $(SOURCES:.cpp=.o)

all: Pong

Pong: $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@ 

main.o: main.cpp headers.h globals.h pongWorld.h
	$(CC) $(FLAGS) main.cpp $(LIBS)

ball.o: ball.cpp ball.h headers.h globals.h
	$(CC) $(FLAGS) ball.cpp $(LIBS)

pongWorld.o: pongWorld.cpp pongWorld.h headers.h globals.h ball.h player.h
	$(CC) $(FLAGS) pongWorld.cpp $(LIBS)

player.o: player.cpp player.h headers.h globals.h 
	$(CC) $(FLAGS) player.cpp $(LIBS)

clean: 
	rm -rf *o *~ Pong