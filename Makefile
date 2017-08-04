CC = g++ -std=c++0x
CFLAGS = -c 
OBJ = main.o buildMap.o mapNode.o

findOP : $(OBJ)
	$(CC) -o findOP $(OBJ)

main.o : main.cpp buildMap.h
	$(CC) $(CFLAGS) main.cpp

buildMap.o : buildMap.cpp buildMap.h mapNode.h
	$(CC) $(CFLAGS) buildMap.cpp
mapNode.o : mapNode.cpp mapNode.h
	$(CC) $(CFLAGS) mapNode.cpp

clean:
	rm findOP *.o
