GCC = gcc
BIN = ./bin
LIB = ./lib
INC = ./include 
SRC = ./src
TEST= ./test
CLI = $(TEST)/client
SRV = $(TEST)/server

clean:
	rm ./lib/*.o ./bin/server ./bin/client

all: $(LIB)/Socket.o $(LIB)/t_financiera.o $(LIB)/Tarjeta.o $(BIN)/server $(BIN)/client 

$(BIN)/server: $(SRV)/mainServer.c
	$(GCC) $(SRV)/mainServer.c -I$(INC) -o $(BIN)/server $(LIB)/Socket.o $(LIB)/t_financiera.o $(LIB)/Tarjeta.o

$(BIN)/client: $(CLI)/test_financiera.c
	$(GCC) $(CLI)/test_financiera.c -I$(INC) -o $(BIN)/client $(LIB)/Socket.o $(LIB)/t_financiera.o

$(LIB)/Socket.o: $(SRC)/Socket.c
	$(GCC) -c $(SRC)/Socket.c -o $(LIB)/Socket.o -I$(INC)
																			
$(LIB)/t_financiera.o: $(SRC)/t_financiera.c
	$(GCC) -c $(SRC)/t_financiera.c -o $(LIB)/t_financiera.o -I$(INC)

$(LIB)/Tarjeta.o: $(SRC)/Tarjeta.c
	$(GCC) -c $(SRC)/Tarjeta.c -o $(LIB)/Tarjeta.o -I$(INC)


