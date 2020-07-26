# Project: Biblioteca Estandar de Grafos. Diogenes Cristaldo

LD			=g++
LDFLAGS		=-m64 -ggdb -fPIC

HOME_LIB 	= $(pwd)
INCS		=-I./include -g3 -fpermissive -Wreturn-type
LIBS		=./lib
BIN			=./bin
OBJS		=./SHSG
BINS		=./bin/*

install: $(BIN)/Grafos.o
	$(LD) $(LDFLAGS) -Wl,-soname,$(OBJS)/libstdg.so.1 -o $(OBJS)/libstdg.so.1.0 $(BINS) -shared 

$(BIN)/Grafos.o: $(LIBS)/grafos/Grafos.cc
	$(LD) -Wall  $(LDFLAGS) -c $(LIBS)/grafos/Grafos.cc -o $(BIN)/Grafos.o $(INCS)

$(BIN)/toha.o: $(LIBS)/toha.cc
	$(LD) -Wall  $(LDFLAGS) -c $(LIBS)/toha.cc -o $(BIN)/toha.o $(INCS)
