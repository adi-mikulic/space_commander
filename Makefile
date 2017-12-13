CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game
SOURCES=Cart_Point.cpp \
Cart_Vector.cpp Game_Object.cpp Oxygen_Depot.cpp Space_Station.cpp Person.cpp Astronaut.cpp Alien.cpp Model.cpp Game_Command.cpp View.cpp main.cpp

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# g++ Cart_Point.cpp Cart_Vector.cpp Game_Object.cpp Oxygen_Depot.cpp Space_Station.cpp Person.cpp Astronaut.cpp Alien.cpp Model.cpp Game_Command.cpp View.cpp main.cpp -g -o game
