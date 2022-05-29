all: runMovies

runMovies: main.cpp movie.o
	g++ -std=c++11 main.cpp movie.o -o runMovies

clean: 
	remove *.o runMovies