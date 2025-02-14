INCLUDE_DIR=../Include/
SOURCE_DIR=../Source/

CC=g++
CFLAGS= -I$(INCLUDE_DIR) 

OBJ= main.o functions.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFLAGS)

functions.o: $(SOURCE_DIR)/functions.cpp
	$(CC) -c $(SOURCE_DIR)/functions.cpp $(CFLAGS)

clean:
	rm -f *.o Output
