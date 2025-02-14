INCLUDE_DIR=../Include/
SOURCE_DIR=../Source/

CC=g++
CFLAGS= -I$(INCLUDE_DIR) 

OBJ= main.o book.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFLAGS)

book.o: $(SOURCE_DIR)/book.cpp
	$(CC) -c $(SOURCE_DIR)/book.cpp $(CFLAGS)

clean:
	rm -f *.o Output
