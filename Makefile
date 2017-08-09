CC = g++ -std=c++0x
CFLAGS = -c 
OBJ = main.o buildMap.o

findOP : $(OBJ)
	$(CC) -o findOP $(OBJ)

main.o : main.cpp buildMap.h
	$(CC) $(CFLAGS) main.cpp

buildMap.o : buildMap.cpp buildMap.h
	$(CC) $(CFLAGS) buildMap.cpp

clean:
	rm findOP *.o
