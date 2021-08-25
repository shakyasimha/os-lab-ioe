$(CC) = gcc

bankers: bankers.o
	$(CC) bankers.o -o bankers

bankers.o: bankers.c
	$(CC) -c bankers.c

clean:
	rm bankers.o bankers
