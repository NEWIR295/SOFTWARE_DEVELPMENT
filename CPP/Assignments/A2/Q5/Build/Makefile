INCLUDE_DIR=../Include/
SOURCE_DIR=../Source/

CC=g++
CFLAGS= -I$(INCLUDE_DIR) 

OBJ= main.o car.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFLAGS)

car.o: $(SOURCE_DIR)/car.cpp
	$(CC) -c $(SOURCE_DIR)/car.cpp $(CFLAGS)

clean:
	rm -f *.o Output
