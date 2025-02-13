INCLUDE_DIR=../Include/
SOURCE_DIR=../Source/

CC=g++
CFLAGS= -I$(INCLUDE_DIR) 

OBJ= main.o point.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFLAGS)

point.o: $(SOURCE_DIR)/point.cpp
	$(CC) -c $(SOURCE_DIR)/point.cpp $(CFLAGS)

clean:
	rm -f *.o Output
