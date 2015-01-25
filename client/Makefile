include ../Makefile.include

CFLAGS_=$(CFLAGS) -std=c++11
LDFLAGS=-lsensors
SOURCES=client.cpp LibsensorManager.cpp LibsensorSensor.cpp Jsonifier.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=../$(CLIENT_EXECUTABLE)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS_) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	
