PP1: main.o 
	g++ -o PP1 main.o

main.o: main.cpp 
	g++ -c main.cpp

clean: 
	rm *.o PP1