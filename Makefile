all: runMovies

runMovies: main.cpp movies.o
	g++ -std=c++11 main.cpp movies.o -o runMovies

clean: 
	remove *.o runMovies