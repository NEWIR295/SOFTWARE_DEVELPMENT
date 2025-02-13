INCLUDE_DIR=../Include/
SOURCE_DIR=../Source/

CC=g++
CFLAGS= -I$(INCLUDE_DIR) 

OBJ= main.o dynamicMatrix.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFLAGS)

dynamicMatrix.o: $(SOURCE_DIR)/dynamicMatrix.cpp
	$(CC) -c $(SOURCE_DIR)/dynamicMatrix.cpp $(CFLAGS)

clean:
	rm -f *.o Output
