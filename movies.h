#include <vector>
#include <string>
using namespace std;

#define MOVIES_H

class Movie{
    public:
        string getTitle(){return title;}
        double getRating() {return rating;}

        Movie(string title, double rating);
        Movie();
        bool operator>(const Movie& m);
        bool operator<(const Movie& m);
        bool operator==(const Movie& m);

    private:
        string title;
        double rating;
};

bool compare_rating(Movie m1, Movie m2);