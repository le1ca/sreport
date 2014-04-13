CC=g++
CFLAGS=-c -Wall -Wextra -Wpedantic
LDFLAGS=-lsensors
SOURCES=sreport.cpp LibsensorManager.cpp LibsensorSensor.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sreport

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

test: clean all
	./$(EXECUTABLE)
	
