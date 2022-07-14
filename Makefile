# Project: Biblioteca Estandar de Grafos. Diogenes Cristaldo

LD		=g++
LDFLAGS		=-m64 -ggdb -fPIC

HOME_LIB 	= $(pwd)
INCS		=-I./include -g3 -fpermissive -Wreturn-type
SRC		=./src
BIN		=./bin
OBJS		=./lib
BINS		=./bin/*

clean: 
	rm -rf ./bin/*.o
install: $(BIN)/Grafos.o
	$(LD) $(LDFLAGS) -Wl,-soname,$(OBJS)/libstdg.so.1 -o $(OBJS)/libstdg.so.1.0 $(BINS) -shared 

$(BIN)/Grafos.o: $(SRC)/grafos/Grafos.cc
	$(LD) -Wall  $(LDFLAGS) -c $(SRC)/grafos/Grafos.cc -o $(BIN)/Grafos.o $(INCS)

$(BIN)/toha.o: $(SRC)/toha.cc
	$(LD) -Wall  $(LDFLAGS) -c $(SRC)/toha.cc -o $(BIN)/toha.o $(INCS)
