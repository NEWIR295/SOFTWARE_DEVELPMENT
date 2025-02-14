INCLUDE_DIR=../Include/
SOURCE_DIR=../Source/

CC=g++
CFLAGS= -I$(INCLUDE_DIR) 

OBJ= main.o dynamicArray.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFLAGS)

dynamicArray.o: $(SOURCE_DIR)/dynamicArray.cpp
	$(CC) -c $(SOURCE_DIR)/dynamicArray.cpp $(CFLAGS)

clean:
	rm -f *.o Output
