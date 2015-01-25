include Makefile.include

all: $(CLIENT_EXECUTABLE) $(SERVER_EXECUTABLE)

$(CLIENT_EXECUTABLE): client
	make -C client
	
$(SERVER_EXECUTABLE): server
	make -C server
	
clean:
	make -C client clean
	make -C server clean
