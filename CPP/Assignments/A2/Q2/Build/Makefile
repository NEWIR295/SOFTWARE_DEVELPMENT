SOURCE_DIR=../Source
INCLUDE_DIR=../Include

CC=g++

OBJ=main.o circle.o
CFALGS= -I$(INCLUDE_DIR)

all: $(OBJ)
	$(CC) $(OBJ) $(CFALGS) -o Output

main.o: $(SOURCE_DIR)/main.cpp
	$(CC) -c $(SOURCE_DIR)/main.cpp $(CFALGS)

circle.o: $(SOURCE_DIR)/circle.cpp
	$(CC) -c $(SOURCE_DIR)/circle.cpp $(CFALGS)

clean:
	rm -f *.o Output