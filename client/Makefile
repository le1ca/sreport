include ../Makefile.include

LDFLAGS=-lsensors
SOURCES=client.cpp LibsensorManager.cpp LibsensorSensor.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=../$(CLIENT_EXECUTABLE)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	
