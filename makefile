examen:	main.o
	g++ main.o -o examen
main.o:	main.cpp
	g++ -c main.cpp -std=c++11
