INCLUDE_DIR=../Include/
SOURCE_DIR=../Source/

CC=g++
CFLAGS= -I$(INCLUDE_DIR) 

OBJ= main.o family.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFLAGS)

family.o: $(SOURCE_DIR)/family.cpp
	$(CC) -c $(SOURCE_DIR)/family.cpp $(CFLAGS)

clean:
	rm -f *.o Output
