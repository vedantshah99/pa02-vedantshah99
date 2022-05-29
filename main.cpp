// Spring'22
// Instructor: Diba Mirza
// Student name: 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include "movie.h"
using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
  // Create an object of a STL data-structure to store all the movies
  vector<Movie> movies;

  string line, movieName;
  double movieRating;
  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        Movie temp = Movie(movieName, movieRating);
        movies.push_back(temp);
  }
  
  movieFile.close();
  
  sort(movies.begin(), movies.end());

  if (argc == 2){
        //print all the movies in ascending alphabetical order of movie names
        
        for(int i = 0; i < movies.size(); i++)
        {
            cout << movies[i].getTitle() << endl;
        }

        return 0;
        
  }

  //  For each prefix,
  //  Find all movies that have that prefix and store them in an appropriate data structure
  //  If no movie with that prefix exists print the following message
  
  vector<Movie> bests;

  for(int j = 2; j < argc; j++){
    vector<Movie> prefixMovies;
    bool none = true;
    string prefix = argv[j];

    for(int i = 0; i < movies.size(); i++){
        //cout << lineList[i].substr(0,prefix.length()) << " - " << prefix << endl;
        if(movies[i].getTitle().substr(0,prefix.length()) == prefix){
            prefixMovies.push_back(movies[i]);
            none = false;
        }
    }
    if(!none){
        cout << endl<< "In order of rating: " << endl;
    }

    //printing the list in order of rating
    bool best = true;
    int size = prefixMovies.size();

    for(int k =0; k < size; k++){
        //Movie highest = movies[0];
        int highest =0;
        for(int i = 1 ; i < prefixMovies.size(); i++){
            if(prefixMovies[i].getRating() == prefixMovies[highest].getRating() && prefixMovies[i].getTitle() < prefixMovies[highest].getTitle()){
                highest = i;
            }
            if(prefixMovies[i].getRating() > prefixMovies[highest].getRating()){
                highest = i;
            }
        }
        if(best && !none){
            bests.push_back(prefixMovies[highest]);
            best = false;
        }
        cout << prefixMovies[highest].getTitle() << ", "<< prefixMovies[highest].getRating() << endl;
        prefixMovies.erase(prefixMovies.begin()+ highest);
    }
    if(none){
        cout << "No movies found with prefix "<< prefix << endl;
        bests.push_back(Movie("",0));
    }
    cout << endl;
  }

  //  For each prefix,
  //  Print the highest rated movie with that prefix if it exists.
  
  int i = 0;
  for(int j = 2; j < argc; j++){
    if(bests[i].getTitle() == ""){
    }
    else{
        cout << "Best movie with prefix " << argv[j] << " is: " << bests[i].getTitle() << " with rating " << std::fixed << std::setprecision(1) << bests[i].getRating() << endl;
        i++;
    } 
  }

  return 0;
}

/*
The runtime analyis of my program would be O(m(n+(k^2))). This can be explained since we start by iterating through all the prefixes. 
While doing so, we iterate through all the movies to see which should be added to the prefixMovies list. We then also iterate through
the prefixMovies through a nested for-loop.

The runtime for the alphabetical sort in part (a) would be O(n^2) 
since we are interating thorough each element of the list while iterating through the list1
*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    if (line.length() <= 0) return false;
    string tempRating = "";

    bool flag = false;
    movieName = tempRating = "", movieRating = 0.0, flag = false;

    for (int i = 0; i < line.length(); i++){
        if(flag) tempRating += line[i];
        else if(line[i]==','&& line[0]!='"') flag = true;
        else {
            if(i==0 && line[0]=='"') continue;
            if(line[i]=='"'){ i++; flag=true; continue;}
            movieName += line[i];
        }
    }
    
    movieRating = stod(tempRating);
    return true;
}
