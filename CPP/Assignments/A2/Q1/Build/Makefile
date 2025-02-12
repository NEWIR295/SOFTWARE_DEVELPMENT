INCLUDE_DIR=../Include
SRC_DIR=../Source

CC=g++

CFLAGS= -I$(INCLUDE_DIR)

OBJ= main.o employee.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Output

main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp $(CFLAGS)

employee.o: $(SRC_DIR)/employee.cpp
	$(CC) -c $(SRC_DIR)/employee.cpp $(CFLAGS)

clean:
	rm -f *.o Output


