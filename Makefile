all: runMovies

runMovies: main.cpp
	g++ -std=c++11 main.cpp -o runMovies

clean: 
	remove *.o runMovies