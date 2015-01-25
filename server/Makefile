include ../Makefile.include

LDFLAGS=
SOURCES=server.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=../$(SERVER_EXECUTABLE)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	
