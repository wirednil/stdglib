0=o
# Application paths
SRC_DIR		= ./src
INC_DIR		= ./include
OBJ_DIR		= ./obj
LIB			=  /LSRC
TEST		= ./test

# Module list
OBJ_LIST	= 	$(OBJ_DIR)/Grafos.$(0)	

# Flags Compilers
CXX			=	g++
INCLUDES	=	-I$(INC_DIR) -I$(INC_DIR)/grafos -I$(INC_DIR)/industries
FLAGS		=	-O0 -Wall -Wextra -g


# Rules to compile testing files
cmain: 
	$(CXX) $(FLAGS) $(TEST)/main.cpp  $(INCLUDES) -o main

# Rule to clean all generated objects and library
clean:
	rm -rf obj/*.o $(LIB)/libgraf.* ./main  

# Create symbolic links for libgraf.so.1.0
.PHONY: links
links:
	ln -sf $(LIB)/libgraf.so.1.0 $(LIB)/libgraf.so.1
	ln -sf $(LIB)/libgraf.so.1   $(LIB)/libgraf.so