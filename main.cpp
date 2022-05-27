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
  vector<string> nameList;
  vector<double> ratingList;
  vector<string> lineList;

  string line, movieName;
  double movieRating;
  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        ratingList.push_back(movieRating);
        nameList.push_back(movieName);
        lineList.push_back(line);
  }

  movieFile.close();

  if (argc == 2){
        //print all the movies in ascending alphabetical order of movie names
        vector<string> printList;
        vector<string> tempList = lineList;
        while(printList.size() < lineList.size())
        {
            string first = tempList[0];
            int removeNum =0;
            for(int i = 1 ; i < tempList.size(); i++){
                if(tempList[i] < first){
                    first = tempList[i];
                    removeNum = i;
                }
            }
            printList.push_back(first);
            tempList.erase(tempList.begin()+ removeNum);
            cout << first << endl;
        }

        return 0;
  }

  //  For each prefix,
  //  Find all movies that have that prefix and store them in an appropriate data structure
  //  If no movie with that prefix exists print the following message
  vector<string> bests;
  vector<double> bestsRatings;
  for(int j = 2; j < argc; j++){
    vector<string> prefixList;
    vector<double> prefixRatingList;
    bool none = true;
    string prefix = argv[j];

    for(int i = 0; i < lineList.size(); i++){
        //cout << lineList[i].substr(0,prefix.length()) << " - " << prefix << endl;
        if(lineList[i].substr(0,prefix.length()) == prefix){
            prefixList.push_back(lineList[i]);
            prefixRatingList.push_back(ratingList[i]);
            //cout << lineList[i] << endl;
            none = false;
        }
    }
    cout << endl<< "In order of rating: " << endl;
    //printing the list in order of rating
    vector<string> tempList = prefixList;
    vector<double> tempRatingList = prefixRatingList;
    bool best = true;

    for(int k =0; k < prefixRatingList.size(); k++)
    {
        int highest = 0;
        for(int i = 1 ; i < tempRatingList.size(); i++){
            //cout << tempList[i]<< "____" << tempRatingList[i] << ">" << tempRatingList[highest]<< endl;
            if(tempRatingList[i] == tempRatingList[highest] && tempList[i] < tempList[highest]){
                highest = i;
            }
            if(tempRatingList[i] > tempRatingList[highest]){
                highest = i;
                //cout << "--temp highest: " << tempList[highest] << endl;
            } 
        }
        if(best){
            bests.push_back(tempList[highest]);
            bestsRatings.push_back(tempRatingList[highest]);
            best = false;
        }
        cout << tempList[highest] << endl;
        tempList.erase(tempList.begin()+ highest);
        tempRatingList.erase(tempRatingList.begin()+ highest);
    }
    if(none) cout << "No movies found with prefix "<< prefix << endl << endl;
    cout << endl;
  }

  //  For each prefix,
  //  Print the highest rated movie with that prefix if it exists.
  int i = 0;
  for(int j = 2; j < argc; j++){
    cout << "Best movie with prefix " << argv[j] << " is: " << bests[i].substr(0,bests[i].length()-4) << " with rating " << std::fixed << std::setprecision(1) << bestsRatings[i] << endl;
    i++;
  }

  return 0;
}

/*
The runtime analyis of my program would be 

The runtime for the alphabetical sort in part (a) would be O(n^2) 
since we are interating thorough each element of the list while iterating through the list

The runtime for figuring out with values of the next correspond to the prefix is O(m*n) and the
runtime for sorting them in order of rating is O(m*(k^2)). Therefore the total runtime for part b
would be O(m*(n+k^2))

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
